#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include <cstring>
#include <iomanip>

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

    bool Patient::operator==(char c) const {
        return type() == c;
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
                ostr << m_name << ", OHIP: " << m_OHIP << std::endl;
            }
            else if (&ostr == &std::clog) {
                ostr << std::left << std::setw(53) << std::setfill('.') << m_name;
                ostr << std::right << std::setw(9) << std::setfill(' ') << m_OHIP;
                ostr << std::setw(5) << m_ticket.number() << ' ';
                ostr << m_ticket.time();
            }
            else {
                ostr << type() << ',' << m_name << ',' << m_OHIP << ',';
                m_ticket.write(ostr);
            }
        }
        else {
            ostr << "Invalid Patient Record" << std::endl;
        }
        return ostr;
    }

    std::istream& Patient::read(std::istream& istr) {
        char tempName[51];
        int tempOHIP;
        if (&istr == &std::cin) {
            std::cout << "Name: ";
            istr.get(tempName, 51);
            istr.ignore(1000, '\n');
            std::cout << "OHIP: ";
            while (true) {
                if (!(istr >> tempOHIP)) {
                    istr.clear();
                    istr.ignore(1000, '\n');
                    std::cout << "Bad integer value, try again: ";
                }
                else if (tempOHIP < 100000000 || tempOHIP > 999999999) {
                    istr.ignore(1000, '\n');
                    std::cout << "Invalid value entered, retry [100000000 <= value <= 999999999]: ";
                }
                else {
                    break;
                }
            }
            istr.ignore(1000, '\n');
        }
        else {
            istr.get(tempName, 51, ',');
            istr.ignore(1000, ',');
            istr >> tempOHIP;
            istr.ignore(1000, ',');
            if (istr.peek() != '\n') {
                m_ticket.read(istr);
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