#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <cstring>

namespace seneca {

    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket++), m_symptoms(nullptr) {}

    TriagePatient::TriagePatient(const TriagePatient& other) : Patient(other) {
        if (other.m_symptoms) {
            m_symptoms = new char[strlen(other.m_symptoms) + 1];
            strcpy(m_symptoms, other.m_symptoms);
        }
        else {
            m_symptoms = nullptr;
        }
    }

    TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
        if (this != &other) {
            Patient::operator=(other);
            delete[] m_symptoms;
            if (other.m_symptoms) {
                m_symptoms = new char[strlen(other.m_symptoms) + 1];
                strcpy(m_symptoms, other.m_symptoms);
            }
            else {
                m_symptoms = nullptr;
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
        if (&ostr == &std::cout) {
            ostr << "TRIAGE" << std::endl;
        }
        Patient::write(ostr);
        if (&ostr == &std::cout) {
            ostr << "Symptoms: " << m_symptoms << std::endl;
        }
        else if (&ostr != &std::clog) {
            ostr << "," << m_symptoms;
        }
        return ostr;
    }

    std::istream& TriagePatient::read(std::istream& istr) {
        delete[] m_symptoms;
        Patient::read(istr);
        if (&istr != &std::cin) {
            char tempSymptoms[512];
            istr.ignore(); // Ignore the comma
            istr.get(tempSymptoms, 512, '\n');
            m_symptoms = new char[strlen(tempSymptoms) + 1];
            strcpy(m_symptoms, tempSymptoms);
            nextTriageTicket = number() + 1;
        }
        else {
            std::cout << "Symptoms: ";
            m_symptoms = new char[512];
            istr.get(m_symptoms, 512, '\n');
            istr.ignore(1000, '\n');
        }
        return istr;
    }

}
