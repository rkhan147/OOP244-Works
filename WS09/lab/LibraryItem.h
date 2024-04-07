/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-04-05

I have done all the coding by myself and only copied the code that 
my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H

#include <iostream>

namespace seneca {
    class LibraryItem {
        char* m_title;
        int m_year;
    public:
        LibraryItem();
        LibraryItem(const char* title, int year);
        LibraryItem(const LibraryItem& other);
        LibraryItem& operator=(const LibraryItem& other);
        virtual ~LibraryItem();

        virtual std::ostream& display(std::ostream& ostr = std::cout) const;
    };
}

#endif // SENECA_LIBRARYITEM_H