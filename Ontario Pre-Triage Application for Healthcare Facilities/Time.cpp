#include "Time.h"
#include "Utils.h"
#include <iomanip>

namespace seneca {
    Time::Time(unsigned int min) : m_minutes(min) {}

    Time& Time::reset() {
        m_minutes = U.getTime();
        return *this;
    }

    void Time::write(std::ostream& os) const {
        os << std::setw(2) << std::setfill('0') << m_minutes / 60
            << ":" << std::setw(2) << std::setfill('0') << m_minutes % 60;
    }

    void Time::read(std::istream& is) {
        int hours, minutes;
        char colon;
        is >> hours >> colon >> minutes;
        if (colon != ':') {
            is.setstate(std::ios::failbit);
        }
        else {
            m_minutes = hours * 60 + minutes;
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
        if (m_minutes < D.m_minutes) {
            m_minutes += 24 * 60;
        }
        m_minutes -= D.m_minutes;
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        Time temp = *this;
        return temp -= T;
    }

    std::ostream& operator<<(std::ostream& os, const Time& T) {
        T.write(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Time& T) {
        T.read(is);
        return is;
    }
}
