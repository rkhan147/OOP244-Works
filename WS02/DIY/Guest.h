/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: January 31, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

namespace seneca {

	struct Guest {
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	};

	void set(Guest& guest, const char* first, const char* last, int age);
	void print(const Guest& guest);
	void book(Guest& guest);
	void vacate(Guest& guest);
}
#endif // !GUEST_H