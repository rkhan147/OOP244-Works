// Patient.h
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
