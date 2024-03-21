/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-03-19

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    SavingsAccount::SavingsAccount(const char* name, const Date& openDate, const DepositInfo& depInfo, double balance, double interest, const Date& interestDate)
        : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

    void SavingsAccount::writeInterest(std::ostream& out) const {
        out << std::fixed << std::setprecision(3) << m_interest << '%';
    }

    void SavingsAccount::applyInterest(const Date& dt) {
        double interestAmount = getBalance() * m_interest;
        setBalance(getBalance() + interestAmount);
        std::cout << "   ";
        writeCurrency(std::cout, getBalance() - interestAmount);
        std::cout << " + ";
        writeCurrency(std::cout, interestAmount);
        std::cout << " (";
        writeInterest(std::cout);
        std::cout << ") = ";
        writeCurrency(std::cout, getBalance());
        std::cout << " | " << m_interestDate << " => " << dt << std::endl;
        m_interestDate = dt;
    }

    std::ostream& SavingsAccount::write(std::ostream& out) const {
        BankAccount::write(out);
        out << " | ";
        writeInterest(out);
        out << " | ";
        m_interestDate.write(out);
        return out;
    }

    std::istream& SavingsAccount::read(std::istream& in) {
        BankAccount::read(in);

        std::cout << "Interest Date ";
        m_interestDate.read(in);

        std::cout << "Interest Rate: ";
        in >> m_interest;
        in.ignore();

        return in;
    }

    std::istream& operator>>(std::istream& in, SavingsAccount& acct) {
        return acct.read(in);
    }

    std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
        return acct.write(out);
    }
}
