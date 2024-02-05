/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: February 04, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

#ifndef SENECA_CAR_H
#define SENECA_CAR_H

namespace seneca {

	class Car {

		char m_licencePlate[9];
		char* m_makeModel;
		char* m_serviceDesc;
		double m_cost;

	public:

		Car();
		~Car();

		bool isEmpty() const;
		void setEmpty();
		void deallocateMemory();
		void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
		void display() const;
	};
}
#endif // !SENECA_CAR_H