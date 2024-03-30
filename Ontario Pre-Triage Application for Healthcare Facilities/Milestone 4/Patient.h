/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.h
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

#ifndef SENECA_PATIENT_H_
#define SENECA_PATIENT_H_

#include "IOAble.h"
#include "Ticket.h"

namespace seneca {
    class Patient : public IOAble {
    private:
        char* name;
        int OHIP;
        Ticket ticket;
    public:
        Patient(int ticketNumber);
        Patient(const Patient& other);
        Patient& operator=(const Patient& other);
        virtual ~Patient();

        virtual char type() const = 0;
        bool operator==(char type) const;
        bool operator==(const Patient& other) const;
        void setArrivalTime();
        Time time() const;
        int number() const;
        operator bool() const;
        const char* operator[](int index) const;

        virtual std::ostream& write(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;
    };
}

#endif // SENECA_PATIENT_H_
