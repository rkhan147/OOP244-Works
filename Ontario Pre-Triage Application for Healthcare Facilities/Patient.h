/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/24  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H

#include "IOAble.h"
#include "Ticket.h"

namespace seneca {

    class Patient : public IOAble {
    private:
        char* m_name;
        int m_OHIP;
        Ticket m_ticket;

    public:
        // Constructor
        Patient(int ticketNumber = 0);

        // Copy constructor
        Patient(const Patient& other);

        // Assignment operator
        Patient& operator=(const Patient& other);

        // Destructor
        ~Patient();

        // Virtual function to return the type of the patient
        virtual char type() const = 0;

        // Comparison operator overloads
        bool operator==(char c) const;
        bool operator==(const Patient& other) const;

        // Modifier to set arrival time
        void setArrivalTime();

        // Query method to get arrival time
        Time time() const;

        // Query method to get ticket number
        int number() const;

        // Cast overloads
        operator bool() const;
        operator const char* () const;

        // Overriding write function
        std::ostream& write(std::ostream& ostr) const override;

        // Overriding read function
        std::istream& read(std::istream& istr) override;
    };
}

#endif // SENECA_PATIENT_H