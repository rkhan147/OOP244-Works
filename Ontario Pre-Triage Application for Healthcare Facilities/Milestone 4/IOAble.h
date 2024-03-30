/* Citation and Sources...
Final Project Milestone 4
Module: IOAble
Filename: IOAble.h
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

#ifndef SENECA_IOABLE_H_
#define SENECA_IOABLE_H_

#include <iostream>

using namespace std;
namespace seneca {
    class IOAble {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual ~IOAble() {}
    };

    std::ostream& operator<<(std::ostream& os, const IOAble& io);
    std::istream& operator>>(std::istream& is, IOAble& io);
}

#endif // SENECA_IOABLE_H_