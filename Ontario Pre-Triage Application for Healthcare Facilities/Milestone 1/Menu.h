/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/07  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>

namespace seneca {

    class Menu {

    private:
        const char* m_text;
        int m_numOptions;
        int m_numTabs;
    public:
        Menu(const char* menuContent, int numberOfTabs = 0);
        ~Menu();
        void display() const;
        int& operator>>(int& selection);
    };
}

#endif // !SENECA_MENU_H