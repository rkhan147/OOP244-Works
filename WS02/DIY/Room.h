/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: January 31, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#include "Guest.h"

#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H

namespace seneca {

	struct Room {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	};

	void set(Room& room, int numberOfGuests, const char* roomNumber);
	void print(const Room& room);
	void book(Room& room);
	void vacate(Room& room);
}
#endif // !SENECA_ROOM_H