/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include "ChequingAccount.h"

namespace seneca {
    ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee)
        : Account(balance), m_transactionFee(transactionFee > 0 ? transactionFee : 0.0),
        m_monthlyFee(monthlyFee > 0 ? monthlyFee : 0.0) {}

    bool ChequingAccount::credit(double amount) {
        bool success = Account::credit(amount);
        if (success) {
            Account::debit(m_transactionFee);
        }
        return success;
    }

    bool ChequingAccount::debit(double amount) {
        bool success = Account::debit(amount + m_transactionFee);
        return success;
    }

    void ChequingAccount::monthEnd() {
        Account::debit(m_monthlyFee);
    }

    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << std::endl;
        os.setf(std::ios::fixed, std::ios::floatfield);
        os.precision(2);
        os << "Balance: $" << getBalance() << std::endl;
        os << "Per Transaction Fee: " << m_transactionFee << std::endl;
        os << "Monthly Fee: " << m_monthlyFee << std::endl;
    }
}

