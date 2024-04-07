/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-04-05

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "LibraryItem.h"
#include <cstring>

namespace seneca {
    LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char* title, int year) : m_title(new char[strlen(title) + 1]), m_year(year) {
        strcpy(m_title, title);
    }

    LibraryItem::LibraryItem(const LibraryItem& other) : m_title(new char[strlen(other.m_title) + 1]), m_year(other.m_year) {
        strcpy(m_title, other.m_title);
    }

    LibraryItem& LibraryItem::operator=(const LibraryItem& other) {
        if (this != &other) {
            delete[] m_title;
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
            m_year = other.m_year;
        }
        return *this;
    }

    LibraryItem::~LibraryItem() {
        delete[] m_title;
    }

    std::ostream& LibraryItem::display(std::ostream& ostr) const {
        ostr << "Title: " << m_title << " (" << m_year << ")";
        return ostr;
    }
}