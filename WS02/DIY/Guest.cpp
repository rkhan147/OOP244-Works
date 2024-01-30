#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guest.h"

using namespace std;

namespace seneca {

	void set(Guest& guest, const char* first, const char* last, int age) {

		if ((first != nullptr && strcmp(first, "") != 0) && (last != nullptr && strcmp(last, "") != 0)) {

			guest.m_firstName = new char[strlen(first) + 1];
			strcpy(guest.m_firstName, first);
			guest.m_lastName = new char[strlen(last) + 1];
			strcpy(guest.m_lastName, last);
			guest.m_adult = (age >= 18);
		}
		else guest.m_firstName = nullptr, guest.m_lastName = nullptr;
	}
	void print(const Guest& guest) {

		if (guest.m_firstName != nullptr && guest.m_lastName != nullptr) {
			cout << guest.m_firstName << ' ' << guest.m_lastName;

			if (!guest.m_adult) cout << "(child)";
		}
		else cout << "Vacant!";

		cout << endl;
	}
	void book(Guest& guest) {

		int age;
		char first[25];
		char last[25];

		cout << "Name: ";
		cin >> first;
		cout << "Lastname: ";
		cin >> last;
		cout << "Age: ";
		cin >> age;

		set(guest, first, last, age);
	}
	void vacate(Guest& guest) {

		delete[] guest.m_firstName;
		delete[] guest.m_lastName;

		guest.m_firstName = nullptr;
		guest.m_lastName = nullptr;
	}
}