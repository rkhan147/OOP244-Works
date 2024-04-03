#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>

namespace seneca {
    class Menu {
        const char* m_content;
        int m_numOptions;
        int m_numTabs;

    public:
        Menu(const char* menuContent, int numberOfTabs = 0);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        void display() const;
        int& operator>>(int& Selection);
    };
}

#endif // SENECA_MENU_H_