/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: February 04, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Customer.h"

using namespace std;
namespace seneca {

	Customer::Customer() {

		setEmpty();
	}
	Customer::~Customer() {

		deallocateMemory();
	}
	bool Customer::isEmpty() const
	{
		return (m_name == nullptr || m_name[0] == '\0' || m_car == nullptr);
	}
	void Customer::setEmpty() {

		m_id = 0;
		m_name = nullptr;
		m_car = nullptr;
	}
	void Customer::deallocateMemory() {

		delete[] m_name;
		setEmpty();
	}
	void Customer::set(int customerId, const char* name, const Car* car) {

		deallocateMemory();
		if (name != nullptr && name[0] != '\0' && car != nullptr) {

			m_id = customerId;
			
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			
			m_car = car;
		}
	}
	void Customer::display() const {

		cout << setw(15) << left << "Customer ID:" << setw(20) << right << m_id << endl;
		cout << setw(15) << left << "First Name:" << setw(20) << right << m_name << endl;
		m_car->display();
	}
	const Car& Customer::car() const {
		
		return *m_car;
	}
}