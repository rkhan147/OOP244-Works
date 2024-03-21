/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-03-19

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>

namespace seneca {

    BankAccount::BankAccount(const char* name, const Date& openDate, const DepositInfo& depInfo, double balance)
        : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
        strncpy(m_name, name, 50);
        m_name[50] = '\0';
    }

    void BankAccount::writeCurrency(std::ostream& out, double amount) const {
        out << std::fixed << std::setprecision(2) << '$' << amount;
    }

    std::ostream& BankAccount::write(std::ostream& out) const {
        out << ">> " << m_name << " | ";
        writeCurrency(out, m_balance);
        out << " | ";
        m_openDate.write(out);
        out << " | ";
        m_depInfo.write(out);
        return out;
    }

    std::istream& BankAccount::read(std::istream& in) {
        std::cout << "Name: ";
        in.getline(m_name, 51);

        std::cout << "Opening Balance: ";
        in >> m_balance;
        in.ignore();        

        std::cout << "Date Opened ";
        m_openDate.read(in);

        m_depInfo.read(in);
        
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        return in;
    }

    std::istream& operator>>(std::istream& in, BankAccount& acct) {
        return acct.read(in);
    }

    std::ostream& operator<<(std::ostream& out, const BankAccount& acct) {
        return acct.write(out);
    }
}
