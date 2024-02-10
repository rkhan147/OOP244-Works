/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: February 09, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

namespace seneca {

    class Icecream {
    private:
        int flavourChoice;
        int numScoops;
        bool hasWafer;
    public:
        Icecream();
        void getOrder();
        void printOrder();
        double getTotalPrice();
    };
}
#endif // !SENECA_ICECREAM_H