#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"

namespace seneca {
    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket++), symptoms(nullptr) {}

    TriagePatient::TriagePatient(const TriagePatient& other) : Patient(other) {
        if (other.symptoms != nullptr) {
            symptoms = new char[strlen(other.symptoms) + 1];
            strcpy(symptoms, other.symptoms);
        }
        else {
            symptoms = nullptr;
        }
    }

    TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
        if (this != &other) {
            Patient::operator=(other);
            delete[] symptoms;
            if (other.symptoms != nullptr) {
                symptoms = new char[strlen(other.symptoms) + 1];
                strcpy(symptoms, other.symptoms);
            }
            else {
                symptoms = nullptr;
            }
        }
        return *this;
    }

    TriagePatient::~TriagePatient() {
        delete[] symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    std::ostream& TriagePatient::write(std::ostream& os) const {
        if (&os == &std::cout) {
            os << "TRIAGE\n";
        }
        Patient::write(os);
        if (&os == &std::cout) {
            os << "Symptoms: " << (symptoms != nullptr ? symptoms : "") << "\n";
        }
        else if (&os != &std::clog) {
            os << "," << (symptoms != nullptr ? symptoms : "");
        }
        return os;
    }

    std::istream& TriagePatient::read(std::istream& is) {
        Patient::read(is);
        if (&is == &std::cin) {
            std::cout << "Symptoms: ";
            char tempSymptoms[512];
            is.get(tempSymptoms, 512, '\n');
            is.ignore(10000, '\n');
            symptoms = new char[strlen(tempSymptoms) + 1];
            strcpy(symptoms, tempSymptoms);
        }
        else {
            is.ignore(1, ',');
            char tempSymptoms[512];
            is.get(tempSymptoms, 512, ',');
            is.ignore(10000, ',');
            symptoms = new char[strlen(tempSymptoms) + 1];
            strcpy(symptoms, tempSymptoms);
            nextTriageTicket = number() + 1;
        }
        return is;
    }
}