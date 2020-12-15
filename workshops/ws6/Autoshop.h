/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 08/11/2020
WS6P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
I got help in Car constructor and trim + createInstance function
*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include <list>
#include <vector>

namespace sdds {
	class Autoshop {
	private:
		std::vector<Vehicle*> m_vehicles;
	public:	
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (Vehicle* value : m_vehicles) {
				if (test(value)) {
					vehicles.push_back(value);
				}
			}
		}
	};
}

#endif