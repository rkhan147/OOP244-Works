/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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

#include <sstream>
#include "Menu.h"

using namespace std;
namespace seneca {

    Menu::Menu(const char* menuContent, int numberOfTabs)
        : m_text(menuContent), m_numOptions(0), m_numTabs(numberOfTabs) {

        for (const char* p = m_text; *p; ++p) {

            if (*p == '\n') {
                ++m_numOptions;
            }
        }
    }

    void Menu::display() const {
        string tabIndent(m_numTabs * 3, ' ');
        istringstream iss(m_text);
        string line;

        while (getline(iss, line, '\n')) {
            cout << tabIndent << line << endl;
        }
        cout << tabIndent << "0- Exit" << endl;
        cout << tabIndent << "> ";
    }

    int& Menu::operator>>(int& selection) {

        display();
        cin >> selection;

        while (cin.fail() || selection < 0 || selection > m_numOptions || cin.get() != '\n') {

            if (selection < 0 || selection > m_numOptions) {
                cout << "Invalid value enterd, retry[0 <= value <= 2]: ";
            }
            else if (cin.fail()) {
                cout << "Bad integer value, try again: ";
            }
            else {
                cout << "Only enter an integer, try again: ";
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> selection;
        }

        return selection;
    }
}