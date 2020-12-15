/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 08/11/2020
WS6P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
I got help in Car constructor and trim + createInstance function
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include <string>
#include <cstring>

namespace sdds {
	class Car : public Vehicle {
	private:
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car(std::istream& is);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void trim(std::string& str) const;
	};
	
}

#endif