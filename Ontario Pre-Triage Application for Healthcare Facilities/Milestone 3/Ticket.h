/* Citation and Sources...
Final Project Milestone 1
Module: Ticket
Filename: Ticket.h
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

#ifndef SENECA_TICKET_H_
#define SENECA_TICKET_H_
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace seneca {
   class Ticket:public IOAble{
      Time m_time;
      int m_number;
   public:
      Ticket(int number);
      Time time()const;
      int number()const;
      void resetTime();
      std::ostream& write(std::ostream& ostr )const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SENECA_TICKET_H_
