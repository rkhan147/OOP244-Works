/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-03-19

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H

#include "BankAccount.h"

namespace seneca {

    class SavingsAccount : public BankAccount {
        double m_interest;
        Date m_interestDate;

        void writeInterest(std::ostream& out) const;

    public:
        SavingsAccount(const char* name, const Date& openDate, const DepositInfo& depInfo, double balance, double interest, const Date& interestDate);
        void applyInterest(const Date& dt);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);

        friend std::istream& operator>>(std::istream& in, SavingsAccount& acct);
        friend std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
    };
}

#endif // SENECA_SAVINGSACCOUNT_H
