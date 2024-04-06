/* Citation and Sources...
Final Project Milestone 3
Module: Ticket
Filename: Ticket.h
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
#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_

#include <iostream>
#include "Time.h"
#include "IOAble.h"

namespace seneca {
    class Ticket : public IOAble {
        Time m_time; // Time the ticket was issued
        int m_number; // Sequential ticket number, unique for each lineup

    public:
        /**
         * @brief Constructor to initialize Ticket object with a given ticket number.
         * @param number Sequential ticket number.
         */
        Ticket(int number);

        /**
         * @brief Query function to get the time when the ticket was issued.
         * @return Time object representing the ticket issuance time.
         */
        Time time() const;

        /**
         * @brief Query function to get the ticket number.
         * @return Sequential ticket number.
         */
        int number() const;

        /**
         * @brief Resets the ticket issuance time to the current time.
         */
        void resetTime();

        /**
         * @brief Writes the ticket information to the output stream.
         * @param ostr Reference to the output stream.
         * @return Reference to the output stream.
         */
        std::ostream& write(std::ostream& ostr) const override;

        /**
         * @brief Reads the ticket information from the input stream.
         * @param istr Reference to the input stream.
         * @return Reference to the input stream.
         */
        std::istream& read(std::istream& istr) override;
    };
}

#endif // !SENECA_TICKET_H_