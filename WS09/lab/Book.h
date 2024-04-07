/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-04-05

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "LibraryItem.h"

namespace seneca {
    class Book : public LibraryItem {
        char* m_author;
    public:
        Book(const char* title, int year, const char* author);
        Book(const Book& other);
        Book& operator=(const Book& other);
        ~Book();

        std::ostream& display(std::ostream& ostr = std::cout) const override;
        bool operator >(const Book& other) const;
    };
}

#endif // SENECA_BOOK_H