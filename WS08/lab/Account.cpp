/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include "Account.h"

namespace seneca {
    Account::Account(double balance) : m_balance(balance > 0 ? balance : 0.0) {}

    bool Account::credit(double amount) {
        if (amount <= 0) return false;
        m_balance += amount;
        return true;
    }

    bool Account::debit(double amount) {
        if (amount <= 0 || amount > m_balance) return false;
        m_balance -= amount;
        return true;
    }

    double Account::getBalance() const {
        return m_balance;
    }
}
