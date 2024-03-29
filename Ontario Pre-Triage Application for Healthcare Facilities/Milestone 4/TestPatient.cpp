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