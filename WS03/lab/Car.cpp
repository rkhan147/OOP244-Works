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
#include "Car.h"

using namespace std;
namespace seneca {

	Car::Car() {
		setEmpty();
	}
	Car::~Car() {
		deallocateMemory();
	}
	bool Car::isEmpty() const {

		return m_makeModel == nullptr || m_serviceDesc == nullptr || m_makeModel[0] == '\0' || m_serviceDesc[0] == '\0';
	}
	void Car::setEmpty() {

		m_licencePlate[0] = '\0';
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
		m_cost = 0.0;
	}
	void Car::deallocateMemory() {

		delete[] m_makeModel;
		delete[] m_serviceDesc;
		setEmpty();
	}
	void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {

		deallocateMemory();
		if (plateNo[0] != '\0' &&
			carMakeModel != nullptr && serviceDesc != nullptr &&
			carMakeModel[0] != '\0' && serviceDesc[0] != '\0') {

			strncpy(m_licencePlate, plateNo, 8);
			m_licencePlate[8] = '\0';

			m_makeModel = new char[strlen(carMakeModel) + 1];
			strcpy(m_makeModel, carMakeModel);

			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			strcpy(m_serviceDesc, serviceDesc);

			m_cost = serviceCost;
		}
	}
	void Car::display() const {

		if (!(this->isEmpty())) {
			cout << setw(15) << left << "License Plate:" << setw(20) << right << m_licencePlate << endl;
			cout << setw(15) << left << "Model:" << setw(20) << right << m_makeModel << endl;
			cout << setw(15) << left << "Service Name:" << setw(20) << right << m_serviceDesc << endl;
			cout << setw(15) << left << "Service Cost:" << setw(20) << right << fixed << setprecision(2) << m_cost << endl;
		}
	}
}