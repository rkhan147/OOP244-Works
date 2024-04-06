/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/13  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>

namespace seneca {
    class Menu {
        const char* m_content; // Content of the menu
        int m_numOptions; // Number of options in the menu
        int m_numTabs; // Number of indentation tabs

    public:
        /**
         * @brief Constructor to initialize a Menu object.
         * @param menuContent Pointer to the content of the menu.
         * @param numberOfTabs Number of indentation tabs (default = 0).
         */
        Menu(const char* menuContent, int numberOfTabs = 0);

        /**
         * @brief Destructor to deallocate dynamically allocated memory.
         */
        ~Menu();

        // Disallow copying and assignment
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        /**
         * @brief Display the menu content with options and prompt.
         */
        void display() const;

        /**
         * @brief Overload of insertion operator to receive user selection.
         * @param Selection Reference to store user selection.
         * @return Reference to the integer containing user selection.
         */
        int& operator>>(int& Selection);
    };
}

#endif // SENECA_MENU_H_