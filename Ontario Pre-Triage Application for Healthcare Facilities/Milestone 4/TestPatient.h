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
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_TESTPATIENT_H_
#define SENECA_TESTPATIENT_H_

#include "Patient.h"

namespace seneca {
    class TestPatient : public Patient {
    public:
        TestPatient();

        virtual char type() const override;
        virtual std::ostream& write(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;
    };
}

#endif // SENECA_TESTPATIENT_H_