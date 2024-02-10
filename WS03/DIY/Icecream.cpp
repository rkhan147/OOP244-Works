/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: February 09, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#include <iostream>
#include <iomanip>
#include "Icecream.h"

using namespace std;
namespace seneca {

    Icecream::Icecream() : flavourChoice(0), numScoops(0), hasWafer(false) {}

    void Icecream::getOrder() {
        cout << "Select flavour:\n"
            << "----------------\n"
            << "1: Chocolate\n"
            << "2: Strawberry\n"
            << "3: Mango\n"
            << "4: Tutti fruit\n"
            << "5: Almond crunch\n"
            << "----------------\n"
            << "> ";
        while (!(cin >> flavourChoice) || flavourChoice < 1 || flavourChoice > 5) {

            if (cin.fail()) {

                cout << "Invalid entry, retry\n> ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {

                cout << "Invlid value(1<=val<=5)\n> ";
            }
        }

        cout << "Number of Scoops (max 3)\n> ";
        while (!(cin >> numScoops) || numScoops < 1 || numScoops > 3) {

            if (cin.fail()) {

                cout << "Invalid entry, retry\n> ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {

                cout << "Invlid value(1<=val<=3)\n> ";
            }
        }

        char waferChoice;
        cout << "Vanilla wafer cone?\n(Y)es/(N)o > ";
        while (!(cin >> waferChoice) || (waferChoice != 'Y' && waferChoice != 'y' && waferChoice != 'N' && waferChoice != 'n')) {
            cout << "Only Y or N are acceptable:\n> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        hasWafer = (waferChoice == 'Y' || waferChoice == 'y');
    }

    void Icecream::printOrder() {
        cout << "Order details:                Price\n"
            << "-----------------------------------\n"
            << "Number of scoops, " << numScoops << " total:    " << fixed << setprecision(2) << (double)numScoops * 5 << "\n";

        double flavourPrice = 0.0;
        switch (flavourChoice) {
        case 1:
            cout << "Chocolate flavour:             " << numScoops * 1.0 << "\n";
            flavourPrice = numScoops * 1.0;
            break;
        case 2:
            cout << "Strawberry flavour\n";
            break;
        case 3:
            cout << "Mango flavour\n";
            break;
        case 4:
            cout << "Tutti fruit flavour\n";
            break;
        case 5:
            cout << "Almond crunch flavour\n";
            break;
        default:
            break;
        }

        cout << "Vanilla Wafer:                 ";
        if (hasWafer)
            cout << "5.00\n";
        else
            cout << "0.00\n";

        double totalPrice = numScoops * 5.0 + flavourPrice + (hasWafer ? 5.0 : 0.0);
        cout << "Price:                        " << totalPrice << "\n";
    }

    double Icecream::getTotalPrice() {
        double flavourPrice = 0.0;
        switch (flavourChoice) {
        case 1:
            flavourPrice = numScoops * 1.0;
            break;
        default:
            break;
        }

        return numScoops * 5.0 + flavourPrice + (hasWafer ? 5.0 : 0.0);
    }
}