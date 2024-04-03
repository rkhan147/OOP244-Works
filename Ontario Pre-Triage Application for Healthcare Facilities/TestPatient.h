#ifndef SENECA_TESTPATIENT_H
#define SENECA_TESTPATIENT_H

#include "Patient.h"

namespace seneca {

    extern int nextTestTicket;

    class TestPatient : public Patient {
    public:
        TestPatient();

        char type() const override;

        std::ostream& write(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };
}

#endif // SENECA_TESTPATIENT_H
