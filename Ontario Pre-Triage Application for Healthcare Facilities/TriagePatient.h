#ifndef SENECA_TRIAGEPATIENT_H_
#define SENECA_TRIAGEPATIENT_H_

#include "Patient.h"

namespace seneca {

    extern int nextTriageTicket;

    class TriagePatient : public Patient {
    private:
        char* m_symptoms;

    public:
        TriagePatient();
        TriagePatient(const TriagePatient& other);
        TriagePatient& operator=(const TriagePatient& other);
        ~TriagePatient();

        char type() const override;

        std::ostream& write(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };

}

#endif // SENECA_TRIAGEPATIENT_H_
