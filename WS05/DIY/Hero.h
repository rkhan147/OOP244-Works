#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"

namespace seneca {
	
	class Hero {

		char heroName[MAX_NAME_LENGTH + 1];
		Power* powers;
		int numberOfPowers;
		int powerLevel;

	public:

		Hero();
		Hero(const char* heroName, Power* powers, int numberOfPowers);
		~Hero();

		std::ostream& display() const;
		Hero& operator+=(const Power& power);
		Hero& operator-=(int value);
		friend bool operator<(const Hero& h1, const Hero& h2);
		friend bool operator>(const Hero& h1, const Hero& h2);
		friend Power& operator>>(Power& power, Hero& hero);
		friend Hero& operator<<(Hero& hero, const Power& power);
	};
}
#endif