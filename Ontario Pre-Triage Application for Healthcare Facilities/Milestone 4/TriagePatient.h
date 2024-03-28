#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H

#include "Patient.h"

namespace seneca {
    class TriagePatient : public Patient {
        char* m_symptoms;
    public:
        TriagePatient(int ticketNumber = 0);
        TriagePatient(const TriagePatient& other);
        TriagePatient& operator=(const TriagePatient& other);
        virtual ~TriagePatient();

        virtual char type() const override;
        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;
    };
}

#endif // TRIAGEPATIENT_H