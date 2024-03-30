/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.cpp
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

#include "TestPatient.h"

namespace seneca {
    int nextTestTicket = 1;

    TestPatient::TestPatient() : Patient(nextTestTicket++) {}

    char TestPatient::type() const {
        return 'C';
    }

    std::ostream& TestPatient::write(std::ostream& os) const {
        if (&os == &std::cout) {
            os << "Contagion TEST\n";
        }
        Patient::write(os);
        return os;
    }

    std::istream& TestPatient::read(std::istream& is) {
        Patient::read(is);
        if (&is != &std::cin) {
            nextTestTicket = number() + 1;
        }
        return is;
    }
}