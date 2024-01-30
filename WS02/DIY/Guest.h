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