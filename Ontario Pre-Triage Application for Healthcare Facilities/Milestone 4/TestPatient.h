#ifndef TESTPATIENT_H
#define TESTPATIENT_H

#include "Patient.h"

namespace seneca {
    class TestPatient : public Patient {
    public:
        TestPatient(int ticketNumber = 0);
        virtual char type() const override;
        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;
    };
}

#endif // TESTPATIENT_H