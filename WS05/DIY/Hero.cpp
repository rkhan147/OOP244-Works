/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-02-29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace seneca {
    void Hero::updatePowerLevel() {

        powerLevel = 0;
        for (int i = 0; i < numberOfPowers; i++) {

            powerLevel += powers[i].checkRarity();
        }
        powerLevel *= numberOfPowers;
    }
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
    Hero& Hero::operator+=(const Power& power) {

        if (power.checkName() && power.checkName()[0] != '\0' && power.checkRarity() > 0) {

            Power* temp = new Power[numberOfPowers + 1];
            for (int i = 0; i < numberOfPowers; i++) {

                temp[i] = powers[i];
            }
            temp[numberOfPowers] = power;
            delete[] powers ;
            powers = temp;
            numberOfPowers++;
            updatePowerLevel();
        }
        return *this;
    }
    Hero& Hero::operator-=(int value) {

        if (value > 0) {

            powerLevel -= value;
            if (powerLevel < 0) {

                powerLevel = 0;
            }
        }
        return *this;
    }
    bool Hero::operator<(const Hero& other) const {

        return powerLevel < other.powerLevel;
    }

    bool Hero::operator>(const Hero& other) const {

        return powerLevel > other.powerLevel;
    }

    Hero& operator>>(Power& power, Hero& hero) {

        hero += power;
        return hero;
    }

    Hero& operator<<(Hero& hero, Power& power) {

        hero += power;
        return hero;
    }
}