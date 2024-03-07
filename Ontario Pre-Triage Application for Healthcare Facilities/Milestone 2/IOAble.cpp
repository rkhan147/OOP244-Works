#include "IOAble.h"

namespace seneca {
    ostream& operator<<(ostream& os, const IOAble& io) {
        return io.write(os);
    }

    istream& operator>>(istream& is, IOAble& io) {
        return io.read(is);
    }
}