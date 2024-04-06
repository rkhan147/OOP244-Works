/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.h
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
#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H

#include "Patient.h"

namespace seneca {

    extern int nextTestTicket;

    class TestPatient : public Patient {
    public:
        // Default constructor
        TestPatient();

        // Overriding type() function
        char type() const override;

        // Overriding write function
        std::ostream& write(std::ostream& ostr) const override;

        // Overriding read function
        std::istream& read(std::istream& istr) override;
    };
}

#endif // SENECA_TESTPATIENT_H