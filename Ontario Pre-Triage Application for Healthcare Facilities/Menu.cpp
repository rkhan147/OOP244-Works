/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#include <string>
#include <sstream>
#include "Menu.h"

namespace seneca {
    Menu::Menu(const char* menuContent, int numberOfTabs)
        : m_content(menuContent), m_numTabs(numberOfTabs) {
        m_numOptions = 0;
        for (const char* ptr = menuContent; *ptr; ++ptr) {
            if (*ptr == '\n') ++m_numOptions;
        }
    }

    Menu::~Menu() {}

    void Menu::display() const {
        std::istringstream menuStream(m_content);
        std::string line;
        while (std::getline(menuStream, line)) {
            for (int i = 0; i < m_numTabs; ++i) {
                std::cout << "   ";
            }
            std::cout << line << std::endl;
        }
        if (m_numTabs > 0) {
            std::cout << "   0- Exit\n   > ";
        }
        else {
            std::cout << "0- Exit\n> ";
        }
    }

    int& Menu::operator>>(int& Selection) {
        display();
        bool validInput = false;
        while (!validInput) {
            std::cin >> Selection;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Bad integer value, try again: ";
            }
            else if (std::cin.peek() != '\n') {
                std::cin.ignore(1000, '\n');
                std::cout << "Only enter an integer, try again: ";
            }
            else if (Selection < 0 || Selection > m_numOptions) {
                std::cout << "Invalid value entered, retry [0 <= value <= "
                    << m_numOptions << "]: ";
            }
            else {
                validInput = true;
            }
        }
        return Selection;
    }
}