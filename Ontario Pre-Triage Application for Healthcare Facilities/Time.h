#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_

#include <iostream>

namespace seneca {
    class Time {
        unsigned int m_minutes;

    public:
        Time(unsigned int min = 0u);
        Time& reset();
        void write(std::ostream& os) const;
        void read(std::istream& is);
        operator unsigned int() const;
        Time& operator*=(int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
    };

    std::ostream& operator<<(std::ostream& os, const Time& T);
    std::istream& operator>>(std::istream& is, Time& T);
}

#endif // !SENECA_TIME_H_
