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