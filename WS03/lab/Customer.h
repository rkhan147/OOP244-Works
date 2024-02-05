/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: February 04, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "Car.h"

namespace seneca {

	class Customer {

		int m_id;
		char* m_name;
		const Car* m_car;

	public:
		Customer();
		~Customer();

		bool isEmpty() const;
		void setEmpty();
		void deallocateMemory();
		void set(int customerId, const char* name, const Car* car);
		void display() const;
		const Car& car()const;
	};
}
#endif // !SENECA_CUSTOMER_H