/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-04-05

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>

namespace seneca {
    Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year), m_author(new char[strlen(author) + 1]) {
        strcpy(m_author, author);
    }

    Book::Book(const Book& other) : LibraryItem(other), m_author(new char[strlen(other.m_author) + 1]) {
        strcpy(m_author, other.m_author);
    }

    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            LibraryItem::operator=(other);
            delete[] m_author;
            m_author = new char[strlen(other.m_author) + 1];
            strcpy(m_author, other.m_author);
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_author;
    }

    std::ostream& Book::display(std::ostream& ostr) const {
        LibraryItem::display(ostr);
        ostr << "\nAuthor: " << m_author;
        return ostr;
    }

    bool Book::operator >(const Book& other) const {
        return strcmp(m_author, other.m_author) > 0;
    }
}