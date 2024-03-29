/* Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.cpp
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

#include "IOAble.h"

namespace seneca {
    std::ostream& operator<<(std::ostream& os, const IOAble& io) {
        return io.write(os);
    }

    std::istream& operator>>(std::istream& is, IOAble& io) {
        return io.read(is);
    }
}