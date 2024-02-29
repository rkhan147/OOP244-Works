/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-02-29
*/

#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"

namespace seneca {
	
	class Hero {

		char heroName[MAX_NAME_LENGTH + 1];
		Power* powers;
		int numberOfPowers;
		int powerLevel;
		void updatePowerLevel();

	public:

		Hero();
		Hero(const char* heroName, Power* powers, int numberOfPowers);
		~Hero();

		std::ostream& display() const;
		Hero& operator+=(const Power& power);
		Hero& operator-=(int value);
		bool operator<(const Hero& other) const;
		bool operator>(const Hero& other) const;
		friend Hero& operator>>(Power& power, Hero& hero);
		friend Hero& operator<<(Hero& hero, Power& power);
	};

}
#endif