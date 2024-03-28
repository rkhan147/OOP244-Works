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

#ifndef PATIENT_H
#define PATIENT_H

#include "IOAble.h"
#include "Ticket.h"

namespace seneca {
    class Patient : public IOAble {
    private:
        static int nextTicketNumber;
        char* m_name;
        int m_OHIP;
        Ticket m_ticket;

    public:
        Patient(int ticketNumber = 0);
        Patient(const Patient&);
        Patient& operator=(const Patient&);
        virtual ~Patient(); // Add virtual destructor

        virtual char type() const = 0;
        bool operator==(char) const;
        bool operator==(const Patient&) const;
        void setArrivalTime();
        Time time() const;
        int number() const;

        operator bool() const;
        operator const char* () const;

        virtual std::ostream& write(std::ostream& ostr) const override; // Make write function virtual
        virtual std::istream& read(std::istream& istr) override; // Make read function virtual
    };
}

#endif // PATIENT_H
