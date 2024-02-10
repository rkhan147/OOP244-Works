/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: February 09, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H

#include "Icecream.h"

namespace seneca {

    class Vendor {
    private:
        Icecream* icecreams;
        int numOrders;
        double totalAmount;
        const double TAX_RATE = 0.13;
    public:
        Vendor();
        ~Vendor();
        void setEmpty();
        void takeOrders();
        void displayOrders();
        void clearData();
    };
}
#endif // !SENECA_VENDOR_H