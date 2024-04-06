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
2023/?/?  Debugged DMA
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
    std::ostream& TestPatient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            ostr << "Contagion TEST" << std::endl;
        }
        return Patient::write(ostr);
    }
    std::istream& TestPatient::read(std::istream& istr) {
        Patient::read(istr);
        if (&istr != &std::cin) {
            nextTestTicket = number() + 1;
        }
        return istr;
    }
}
