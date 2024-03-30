/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/30  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <limits>
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

        // Deallocate existing memory for symptoms
        delete[] symptoms;
        symptoms = nullptr;

        // Read symptoms
        if (&is == &std::cin) {
            // Interactive input
            std::cout << "Symptoms: ";
            char tempSymptoms[512];
            is.get(tempSymptoms, 512, '\n');
            is.ignore(10000, '\n');
            symptoms = new char[strlen(tempSymptoms) + 1];
            strcpy(symptoms, tempSymptoms);
        }
        else {
            // Input from file
            is.ignore(1); // Skip comma
            char tempSymptoms[512];
            is.get(tempSymptoms, 512, '\n');
            is.ignore(10000, '\n');
            symptoms = new char[strlen(tempSymptoms) + 1];
            strcpy(symptoms, tempSymptoms);
            nextTriageTicket = number() + 1;
        }

        return is; // Return the input stream
    }
}