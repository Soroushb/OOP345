/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 08/11/2020
WS6P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
I got help in Car constructor and trim + createInstance function
*/
#include "Racecar.h"


namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in){
		in >> m_booster;
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (m_booster + 1);
	}
}