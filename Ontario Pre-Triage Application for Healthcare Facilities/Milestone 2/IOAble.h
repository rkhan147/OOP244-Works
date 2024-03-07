#ifndef SENECA_IOABLE_H_
#define SENECA_IOABLE_H_

#include <iostream>

using namespace std;
namespace seneca {
    class IOAble {
    public:
        virtual ~IOAble() {}
        virtual ostream& write(ostream& ostr) const = 0;
        virtual istream& read(istream& istr) = 0;
    };

    ostream& operator<<(ostream& os, const IOAble& io);
    istream& operator>>(istream& is, IOAble& io);
}

#endif // SENECA_IOABLE_H_