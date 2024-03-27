/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"

namespace seneca {
    class Account : public iAccount {
    private:
        double m_balance;
    public:
        Account(double balance = 0.0);
        virtual bool credit(double amount);
        virtual bool debit(double amount);
        double getBalance() const;
    };
}

#endif
