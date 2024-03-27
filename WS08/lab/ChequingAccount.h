/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include "Account.h"

namespace seneca {
    class ChequingAccount : public Account {
    private:
        double m_transactionFee;
        double m_monthlyFee;
    public:
        ChequingAccount(double balance, double transactionFee, double monthlyFee);
        bool credit(double amount) override;
        bool debit(double amount) override;
        void monthEnd();
        void display(std::ostream&) const override;
    };
}

#endif
