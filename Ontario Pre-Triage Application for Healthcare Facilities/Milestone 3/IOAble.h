/* Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.h
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