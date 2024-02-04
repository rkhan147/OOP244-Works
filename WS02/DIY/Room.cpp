/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: January 31, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

namespace seneca {

	void set(Room& room, int numberOfGuests, const char* roomNumber) {

		room.m_guests = new Guest[numberOfGuests];
		for (int i = 0; i < numberOfGuests; i++) {
			room.m_guests[i].m_firstName = nullptr;
			room.m_guests[i].m_lastName = nullptr;
		}
		room.m_noOfGuests = numberOfGuests;
		strcpy(room.m_roomNumber, roomNumber);
	}
	void print(const Room& room) {
		
		if(room.m_noOfGuests > 0) {
			cout << "Room Number: " << room.m_roomNumber << endl;
			for (int i = 0; i < room.m_noOfGuests; ++i) {
				cout << "    ";
				print(room.m_guests[i]);
			}
		}
		else cout << "Empty Room!" << endl;
    }
	void book(Room& room) {

		int numberOfGuests;
		char roomNumber[6];

		cout << "Room number: ";
		cin >> roomNumber;

		cout << "Number of guests: ";
		cin >> numberOfGuests;

		set(room, numberOfGuests, roomNumber);

		for (int i = 0; i < numberOfGuests; ++i) {
			cout << i + 1 << ':' << endl;
			book(room.m_guests[i]);
		}
	}
	void vacate(Room& room) {

		for (int i = 0; i < room.m_noOfGuests; i++) {

			vacate(room.m_guests[i]);
		}
		delete[] room.m_guests;
		room.m_guests = nullptr;
		room.m_noOfGuests = 0;
	}
}