/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/10/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* m_reservation = nullptr;
		size_t m_cnt = 0;
	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& copy);
		Restaurant(Restaurant&& move);
		Restaurant& operator=(const Restaurant& copy);
		Restaurant& operator=(Restaurant&& move);
		size_t size() const;
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& out, const Restaurant& restaurant);
	};
}

#endif // !SDDS_RESTAURANT_H
