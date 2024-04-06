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
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_TRIAGEPATIENT_H_
#define SENECA_TRIAGEPATIENT_H_

#include "Patient.h"

namespace seneca {

    extern int nextTriageTicket;

    class TriagePatient : public Patient {
    private:
        char* m_symptoms;

    public:
        // Default constructor
        TriagePatient();

        // Copy constructor
        TriagePatient(const TriagePatient& other);

        // Assignment operator
        TriagePatient& operator=(const TriagePatient& other);

        // Destructor
        ~TriagePatient();

        // Overriding type() function
        char type() const override;

        // Overriding write function
        std::ostream& write(std::ostream& ostr) const override;

        // Overriding read function
        std::istream& read(std::istream& istr) override;
    };

}

#endif // SENECA_TRIAGEPATIENT_H_