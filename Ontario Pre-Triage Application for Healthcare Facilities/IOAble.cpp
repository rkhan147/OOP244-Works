#include "IOAble.h"

namespace seneca {

    std::ostream& operator<<(std::ostream& ostr, const IOAble& io) {
        return io.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& io) {
        return io.read(istr);
    }
}