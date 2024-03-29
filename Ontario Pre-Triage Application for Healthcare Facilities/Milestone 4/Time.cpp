/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
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

#include <iomanip>
#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    Time& Time::reset() {
        minutes = U.getTime();
        return *this;
    }

    Time::Time(unsigned int min) : minutes(min) {}

    void Time::write(std::ostream& os) const {
        unsigned int hours = minutes / 60;
        unsigned int mins = minutes % 60;
        os << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << mins;
    }

    void Time::read(std::istream& is) {
        unsigned int hours = 0;
        unsigned int mins = 0;
        char colon;

        is >> hours >> colon >> mins;
        if (colon != ':') {
            is.setstate(std::ios::failbit);
            return;
        }

        minutes = hours * 60 + mins;
    }

    Time::operator unsigned int() const {
        return minutes;
    }

    Time& Time::operator*=(int val) {
        minutes *= val;
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        if (minutes < D.minutes) {
            minutes = 1440 + minutes - D.minutes;
        }
        else {
            minutes -= D.minutes;
        }
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        unsigned int diff;
        if (minutes < T.minutes) {
            diff = 1440 + minutes - T.minutes;
        }
        else {
            diff = minutes - T.minutes;
        }
        return Time(diff);
    }

    std::ostream& operator<<(std::ostream& os, const Time& time) {
        time.write(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Time& time) {
        time.read(is);
        return is;
    }
}