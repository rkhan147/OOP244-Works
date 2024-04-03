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
        Patient(int ticketNumber = 0);
        Patient(const Patient& other);
        Patient& operator=(const Patient& other);
        ~Patient();

        virtual char type() const = 0;

        bool operator==(char c) const;
        bool operator==(const Patient& other) const;

        void setArrivalTime();
        Time time() const;
        int number() const;

        operator bool() const;
        operator const char* () const;

        std::ostream& write(std::ostream& ostr) const override;
        std::istream& read(std::istream& istr) override;
    };
}

#endif // SENECA_PATIENT_H