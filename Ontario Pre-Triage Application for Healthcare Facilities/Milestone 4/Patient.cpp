/* Citation and Sources...
Final Project Milestone 1
Module: Patient
Filename: Patient.cpp
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include "Patient.h"

namespace seneca {
    Patient::Patient(int ticketNumber) : OHIP(0), ticket(ticketNumber) {
        name = nullptr;
    }

    Patient::Patient(const Patient& other) : OHIP(other.OHIP), ticket(other.ticket) {
        if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        else {
            name = nullptr;
        }
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            OHIP = other.OHIP;
            ticket = other.ticket;
            delete[] name;
            if (other.name != nullptr) {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            else {
                name = nullptr;
            }
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] name;
    }

    bool Patient::operator==(char type) const {
        return this->type() == type;
    }

    bool Patient::operator==(const Patient& other) const {
        return this->type() == other.type();
    }

    void Patient::setArrivalTime() {
        ticket.resetTime();
    }

    Time Patient::time() const {
        return ticket.time();
    }

    int Patient::number() const {
        return ticket.number();
    }

    Patient::operator bool() const {
        return name != nullptr;
    }

    const char* Patient::operator[](int index) const {
        if (index == 0) return name;
        else if (index == 1) return std::to_string(OHIP).c_str();
        else return nullptr;
    }

    std::ostream& Patient::write(std::ostream& os) const {
        if (!name) {
            os << "Invalid Patient Record";
            return os;
        }

        if (&os == &std::cout) {
            os << ticket << std::endl << name << ", OHIP: " << OHIP << "\n";
        }
        else if (&os == &std::clog) {
            os << std::setw(53) << std::left << std::setfill('.') << name
                << std::setw(9) << std::right << std::setfill(' ') << OHIP
                << std::setw(5) << std::right << ticket.number() << " " << ticket.time();
        }
        else {
            os << type() << "," << name << "," << OHIP << ",";
            ticket.write(os);
        }
        return os;
    }

    std::istream& Patient::read(std::istream& is) {
        delete[] name;
        name = nullptr;

        if (&is == &std::cin) {
            std::cout << "Name: ";
            char tempName[51];
            is.get(tempName, 51, '\n');
            is.ignore(10000, '\n');
            name = new char[strlen(tempName) + 1];
            strcpy(name, tempName);

            std::cout << "OHIP: ";
            is >> OHIP;
            while (is.fail() || OHIP < 100000000 || OHIP > 999999999) {
                is.clear();
                is.ignore(10000, '\n');
                std::cout << "Invalid value entered, retry [100000000 <= value <= 999999999]: ";
                is >> OHIP;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        }
        else {
            char tempName[51];
            is.get(tempName, 51, ',');
            is.ignore(10000, ',');
            name = new char[strlen(tempName) + 1];
            strcpy(name, tempName);

            is >> OHIP;
            is.ignore(1, ',');

            ticket.read(is);
        }

        return is;
    }
}