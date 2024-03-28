#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"

namespace seneca {
    TriagePatient::TriagePatient(int ticketNumber) : Patient(ticketNumber), m_symptoms(nullptr) {}

    TriagePatient::TriagePatient(const TriagePatient& other) : Patient(other) {
        if (other.m_symptoms != nullptr) {
            m_symptoms = new char[strlen(other.m_symptoms) + 1];
            strcpy(m_symptoms, other.m_symptoms);
        }
    }

    TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
        if (this != &other) {
            Patient::operator=(other);
            delete[] m_symptoms;
            if (other.m_symptoms != nullptr) {
                m_symptoms = new char[strlen(other.m_symptoms) + 1];
                strcpy(m_symptoms, other.m_symptoms);
            }
        }
        return *this;
    }

    TriagePatient::~TriagePatient() {
        delete[] m_symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    std::ostream& TriagePatient::write(std::ostream& ostr) const {
        Patient::write(ostr);
        ostr << "Symptoms: ";
        if (m_symptoms != nullptr) {
            ostr << m_symptoms;
        }
        return ostr << std::endl;
    }

    std::istream& TriagePatient::read(std::istream& istr) {
        Patient::read(istr);
        char tempSymptoms[513]; // Max length of symptoms is 512 characters
        istr.getline(tempSymptoms, 513, ',');
        if (m_symptoms != nullptr) {
            delete[] m_symptoms;
        }
        m_symptoms = new char[strlen(tempSymptoms) + 1];
        strcpy(m_symptoms, tempSymptoms);
        return istr;
    }
}