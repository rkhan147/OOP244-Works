/* Citation and Sources...
Final Project Milestone 1
Module: Patient
Filename: Patient.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace seneca {
    class Patient : public IOAble {
        char* m_name;
        int m_OHIP;
        Ticket m_ticket;

    public:
        Patient(int ticketNumber = 0);
        Patient(const Patient&);
        Patient& operator=(const Patient&);
        ~Patient();

        virtual char type() const = 0;
        bool operator==(char) const;
        bool operator==(const Patient&) const;
        void setArrivalTime();
        Time time() const;
        int number() const;

        operator bool() const;
        operator const char* () const;

        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
}

#endif // SENECA_PATIENT_H_
