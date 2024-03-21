/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-03-19

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#include "DepositUtility.h"

namespace seneca {

    class BankAccount {
        char m_name[51];
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;

    protected:
        double getBalance() const { return m_balance; }
        void setBalance(double balance) { m_balance = balance; }
        void writeCurrency(std::ostream& out, double amount) const;

    public:
        BankAccount(const char* name, const Date& openDate, const DepositInfo& depInfo, double balance);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);

        friend std::istream& operator>>(std::istream& in, BankAccount& acct);
        friend std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
    };
}

#endif // SENECA_BANKACCOUNT_H
