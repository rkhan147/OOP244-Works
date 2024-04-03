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
