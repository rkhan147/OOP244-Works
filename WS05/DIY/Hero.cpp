#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace seneca {

	Hero::Hero() {

		heroName[0] = '\0';
		powers = nullptr;
		numberOfPowers = 0;
		powerLevel = 0;
	}
	Hero::Hero(const char* heroName, Power* powers, int numberOfPowers) {

        strncpy(this->heroName, heroName, MAX_NAME_LENGTH);
        this->heroName[MAX_NAME_LENGTH] = '\0';

        this->powers = new Power[numberOfPowers];
        for (int i = 0; i < numberOfPowers; ++i) {
            this->powers[i] = powers[i];
        }

        this->numberOfPowers = numberOfPowers;

        powerLevel = 0;
        for (int i = 0; i < numberOfPowers; ++i) {
            powerLevel += powers[i].checkRarity();
        }
        powerLevel *= numberOfPowers;
	}
    Hero::~Hero() {

        delete[] powers;
    }
    ostream& Hero::display() const {
        cout << "Name: " << heroName << endl;
        cout << "List of available powers:" << endl;
        for (int i = 0; i < numberOfPowers; ++i) {
            cout << "  Name: " << powers[i].checkName() << ", Rarity: " << powers[i].checkRarity() << endl;
        }
        cout << "Power Level: " << powerLevel;
        return cout;
    }
}