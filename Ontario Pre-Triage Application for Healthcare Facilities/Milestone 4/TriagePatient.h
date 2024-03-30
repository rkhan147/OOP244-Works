/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/30  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_TRIAGEPATIENT_H_
#define SENECA_TRIAGEPATIENT_H_

#include "Patient.h"

namespace seneca {
    class TriagePatient : public Patient {
    private:
        char* symptoms;
    public:
        TriagePatient();
        TriagePatient(const TriagePatient& other);
        TriagePatient& operator=(const TriagePatient& other);
        ~TriagePatient();

        virtual char type() const override;
        virtual std::ostream& write(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;
    };
}

#endif // SENECA_TRIAGEPATIENT_H_