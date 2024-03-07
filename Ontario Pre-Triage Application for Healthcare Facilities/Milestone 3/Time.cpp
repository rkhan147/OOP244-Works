/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/07  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    Time::Time(unsigned int min) : m_minutes(min) {}

    Time& Time::reset() {
        m_minutes = seneca::U.getTime();
        return *this;
    }

    void Time::write(ostream& ostr) const {
        unsigned int hours = m_minutes / 60;
        unsigned int minutes = m_minutes % 60;
        ostr << (hours < 10 ? "0" : "") << hours << ':' << (minutes < 10 ? "0" : "") << minutes;
    }

    void Time::read(istream& istr) {
        unsigned int hours, minutes;
        char colon;
        while (true) {
            istr >> hours;
            if (istr.good() && istr.peek() == ':') {
                istr >> colon >> minutes;
                if (!istr.fail() && colon == ':') {
                    m_minutes = hours * 60 + minutes;
                    break;
                }
            }
            if (istr.eof()) { // end of file, no more data to read
                break;
            }
            istr.clear();
            istr.ignore(1000, '\n');
            if (&istr == &std::cin) { // only print error message for std::cin
                cout << "Bad time entry, retry (HH:MM): ";
            }
        }
    }

    Time::operator unsigned int() const {
        return m_minutes;
    }

    Time& Time::operator*=(int val) {
        m_minutes *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        int diff = static_cast<int>(*this) - static_cast<int>(D);
        if (diff < 0) {
            diff += 24 * 60;
        }
        m_minutes = static_cast<unsigned int>(diff);
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        Time result;
        int diff = static_cast<int>(*this) - static_cast<int>(T);
        if (diff < 0) {
            diff += 24 * 60;
        }
        result.m_minutes = static_cast<unsigned int>(diff);
        return result;
    }

    ostream& operator<<(ostream& os, const Time& time) {
        time.write(os);
        return os;
    }

    istream& operator>>(istream& is, Time& time) {
        time.read(is);
        return is;
    }
}