/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-02-19
*/

/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace seneca
{
    // Default Constructor with default arguments
    bankAccount::bankAccount(const char* name, bool checking)
    {
        m_userName[0] = '\0';       // Empty string implies is account is not open 
        setup(name, checking);
    }

    // Open bank account: setup can only be done once!
    bool bankAccount::setup(const char* name, bool checking)
    {
        if (isOpen())
            return false;
        if (name == nullptr)
            return false;

        strcpy(m_userName, name);
        m_monthlyTransactions = 0;
        m_checking = checking;
        m_funds = 0;
        return true;
    }

    // ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
    bankAccount::operator bool() const
    {
        return isOpen();
    }

    bankAccount::operator double() const
    {
        return m_funds;
    }

    bankAccount& bankAccount::operator++()
    {
        if (isOpen() && m_funds > 0) {
            double interest = m_funds * (m_checking ? CHECKING_INTEREST_RATE : SAVINGS_INTEREST_RATE);
            m_funds += interest;
        }
        return *this;
    }

    bankAccount& bankAccount::operator--()
    {
        if (isOpen()) {
            double fee = (m_checking ? CHECKING_TRANSACTION_FEE : SAVINGS_TRANSACTION_FEE) * m_monthlyTransactions;
            m_funds -= fee;
        }
        return *this;
    }

    bool bankAccount::operator+=(double amount) {
        if (isOpen()) {
            m_funds += amount;
            m_monthlyTransactions++;
            if(amount >= 0) cout << "Deposit $" << fixed << setprecision(2) << amount << " for " << m_userName << endl;
            else cout << "Withdraw $" << fixed << setprecision(2) << amount - amount - amount << " for " << m_userName << endl;
            return true;
        }
        return false;
    }

    bool bankAccount::operator-=(double amount) {
        if (isOpen() && m_funds >= amount) {
            m_funds -= amount;
            m_monthlyTransactions++;
            cout << "Withdraw $" << fixed << setprecision(2) << amount << " for " << m_userName << endl;
            return true;
        }
        return operator+=(-amount);
    }

    bool bankAccount::operator==(const bankAccount& rhs) const {
        return (strcmp(m_userName, rhs.m_userName) == 0 && m_funds - rhs.m_funds < 0.001 && m_checking == rhs.m_checking);
    }

    bool bankAccount::operator>(double amount) const {
        return (isOpen() && m_funds > amount);
    }

    bool bankAccount::operator<=(double amount) const {
        return !(operator>(amount));
    }

    bool bankAccount::operator<<(bankAccount& source) {
        if (isOpen() && source.isOpen() && source.m_funds > 0) {
            double transferAmount = source.m_funds;
            cout << "Transfer $" << fixed << setprecision(2) << transferAmount << " from " << source.m_userName << " to " << m_userName << endl;
            if (*this += transferAmount) {
                source -= transferAmount;
                return true;
            }
        }
        return false;
    }

    void bankAccount::display() const {
        if (isOpen()) {
            cout << "Display Account -> User:" << setw(16) << right << setfill('-') << m_userName << " | "
                << setw(8) << setfill(' ') << (m_checking ? "Checking" : "Savings") << " | Balance: $" << fixed << setprecision(2)
                << setw(8) << setfill(' ') << m_funds << " | Transactions:" << setw(3) << setfill('0') << m_monthlyTransactions << endl;
        }
        else {
            cout << "Display Account -> User:" << setw(16) << right << setfill('-') << " NOT OPEN" << endl;
        }
    }


    // Account is open if user name string is not empty
    bool bankAccount::isOpen() const
    {
        return (m_userName[0] != '\0');
    }

    // ADD: Global Helper Functions

    bool operator>(double lhs, const bankAccount& rhs) {
        return lhs > static_cast<double>(rhs);
    }

    bool operator<=(double lhs, const bankAccount& rhs) {
        return !(lhs > rhs);
    }
}
