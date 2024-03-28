#include "TestPatient.h"

namespace seneca {
    TestPatient::TestPatient(int ticketNumber) : Patient(ticketNumber) {}

    char TestPatient::type() const {
        return 'C';
    }

    std::ostream& TestPatient::write(std::ostream& ostr) const {
        ostr << "Contagion TEST" << std::endl;
        Patient::write(ostr);
        return ostr;
    }

    std::istream& TestPatient::read(std::istream& istr) {
        Patient::read(istr);
        return istr;
    }
}