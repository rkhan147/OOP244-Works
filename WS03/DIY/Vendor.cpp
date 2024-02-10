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
#include "Vendor.h"

using namespace std;
namespace seneca {

    Vendor::Vendor() : icecreams(nullptr), numOrders(0), totalAmount(0.0) {}

    Vendor::~Vendor() {
        clearData();
    }

    void Vendor::setEmpty() {
        clearData();
        icecreams = nullptr;
        numOrders = 0;
        totalAmount = 0.0;
    }

    void Vendor::takeOrders() {
        cout << "Seneca Icecream shop\n"
            << "          @\n"
            << "        (' .)\n"
            << "       (*.`. )\n"
            << "        \\###/\n"
            << "         \\#/\n"
            << "          V\n";

        cout << "How many Icecreams?\n> ";
        cin >> numOrders;

        icecreams = new Icecream[numOrders];
        for (int i = 0; i < numOrders; ++i) {
            cout << "Order number " << i + 1 << ":\n";
            icecreams[i].getOrder();
            totalAmount += icecreams[i].getTotalPrice();
        }
    }

    void Vendor::displayOrders() {
        cout << "********** Order Summary **********";
        double totalTax = totalAmount * TAX_RATE;
        double totalPriceWithTax = totalAmount + totalTax;

        for (int i = 0; i < numOrders; ++i) {
            cout << "\nOrder No: " << i + 1 << ":\n";
            icecreams[i].printOrder();
        }

        cout << "-----------------------------------\n"
            << fixed << setprecision(2)
            << "Price:                        " << totalAmount << "\n"
            << "Tax:                           " << totalTax << "\n"
            << "Total Price ($):              " << totalPriceWithTax << "\n";
    }

    void Vendor::clearData() {

        delete[] icecreams;
        icecreams = nullptr;
    }
}