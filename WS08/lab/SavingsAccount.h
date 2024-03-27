/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author:  
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "Account.h"

namespace seneca {
    class SavingsAccount : public Account {
    private:
        double m_interestRate;
    public:
        SavingsAccount(double balance, double interestRate);
        void monthEnd();
        void display(std::ostream&) const override;
    };
}

#endif
