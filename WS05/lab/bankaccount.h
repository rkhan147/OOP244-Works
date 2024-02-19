/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-02-19
*/

/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
   const int	 ACCT_MAXLEN_USER = 16;					// Max Length of user name

   // Class Definition
   class bankAccount
   {

   private:
      // Data Members
      char	m_userName[ACCT_MAXLEN_USER];
      double	m_funds;
      bool	m_checking;
      int		m_monthlyTransactions;

      const double CHECKING_TRANSACTION_FEE = 1.25;
      const double CHECKING_INTEREST_RATE = 0.005; // 0.5%
      const double SAVINGS_TRANSACTION_FEE = 3.50;
      const double SAVINGS_INTEREST_RATE = 0.025; // 2.5%

      bool isOpen() const;
   public:
      bankAccount(const char* name = nullptr, bool checking = false);
      bool setup(const char* name, bool checking);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
              // Cast operators
      operator bool() const;
      operator double() const;

      // Unary operators
      bankAccount& operator++();
      bankAccount& operator--();

      // Binary operators
      bool operator+= (double);
      bool operator-= (double);
      bool operator== (const bankAccount&) const;
      bool operator> (double) const;
      bool operator<= (double) const;

      // Additional methods
      bool operator<<(bankAccount&);
      void display() const;
   };

   // ADD: Global helpers
   bool operator> (double lhs, const bankAccount& rhs);
   bool operator<= (double lhs, const bankAccount& rhs);
}
#endif