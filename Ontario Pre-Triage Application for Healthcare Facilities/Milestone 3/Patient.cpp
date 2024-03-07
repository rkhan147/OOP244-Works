// Patient.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "Utils.h"

namespace seneca {
    Patient::Patient(int ticketNumber) : m_ticket(ticketNumber) {
        m_name = nullptr;
        m_OHIP = 0;
    }

    Patient::Patient(const Patient& other) : m_ticket(other.m_ticket) {
        m_name = new char[strlen(other.m_name) + 1];
        strcpy(m_name, other.m_name);
        m_OHIP = other.m_OHIP;
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            delete[] m_name;
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
            m_OHIP = other.m_OHIP;
            m_ticket = other.m_ticket;
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] m_name;
    }

    char Patient::type() const {
        return '\0';
    }

    bool Patient::operator==(char ch) const {
        return type() == ch;
    }

    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }

    void Patient::setArrivalTime() {
        m_ticket.resetTime();
    }

    Time Patient::time() const {
        return m_ticket.time();
    }

    int Patient::number() const {
        return m_ticket.number();
    }

    Patient::operator bool() const {
        return m_name != nullptr && m_OHIP >= 100000000 && m_OHIP <= 999999999;
    }

    Patient::operator const char* () const {
        return m_name;
    }

    std::ostream& Patient::write(std::ostream& ostr) const {
        if (this->operator bool()) {
            if (&ostr == &std::cout) {
                ostr << "Ticket No: " << m_ticket.number() << ", Issued at: " << m_ticket.time() << std::endl;
                ostr << m_name << ", OHIP: " << m_OHIP;
            }
            else if (&ostr == &std::clog) {
                ostr << m_name;
                for (int i = 0; i < 53 - strlen(m_name); i++) {
                    ostr << '.';
                }
                ostr << m_OHIP << "   " << m_ticket.number() << " " << m_ticket.time();
            }
            else {
                ostr << type() << ',' << m_name << ',' << m_OHIP << ',';
                m_ticket.write(ostr);
            }
        }
        else {
            ostr << "Invalid Patient Record";
        }
        return ostr;
    }

    std::istream& Patient::read(std::istream& istr) {
        char tempName[51];
        int tempOHIP;
        if (&istr == &std::cin) {
            std::cout << "Name: ";
            istr.get(tempName, 51);
            std::cout << "OHIP: ";
            while (!(istr >> tempOHIP) || tempOHIP < 100000000 || tempOHIP > 999999999) {
                istr.clear();
                istr.ignore(2000, '\n');
                std::cout << "Bad integer value, try again: ";
            }
            istr.ignore(2000, '\n');
        }
        else {
            istr.get(tempName, 51, ',');
            istr.ignore(2000, ',');
            istr >> tempOHIP;
            istr.ignore(2000, ',');
            if (istr.peek() != '\n') { // check if the next character is not a newline
                m_ticket.read(istr); // if it is not, read the Ticket object
            }
        }
        if (m_name != nullptr) {
            delete[] m_name;
        }
        m_name = new char[strlen(tempName) + 1];
        strcpy(m_name, tempName);
        m_OHIP = tempOHIP;
        return istr;
    }

}
