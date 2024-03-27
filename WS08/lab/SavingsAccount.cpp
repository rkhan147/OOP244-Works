/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include "SavingsAccount.h"

namespace seneca {
    SavingsAccount::SavingsAccount(double balance, double interestRate)
        : Account(balance), m_interestRate(interestRate > 0 ? interestRate : 0.0) {}

    void SavingsAccount::monthEnd() {
        double interest = getBalance() * m_interestRate;
        credit(interest);
    }

    void SavingsAccount::display(std::ostream& os) const {
        os << "Account type: Savings" << std::endl;
        os.setf(std::ios::fixed, std::ios::floatfield);
        os.precision(2);
        os << "Balance: $" << getBalance() << std::endl;
        os << "Interest Rate (%): " << m_interestRate * 100 << std::endl;
    }
}
