/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/10/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds {

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {

		m_reservation = new Reservation[cnt];
		if (reservations != nullptr)
		{
			for (size_t i = 0; i < cnt; i++) {
				m_reservation[i] = *reservations[i];
			}
		}
		m_cnt = cnt;
	}
	size_t Restaurant::size() const {
		return m_cnt;
	}
	
	Restaurant::Restaurant(const Restaurant& copy) {
      
		*this = copy;
	}

	Restaurant::Restaurant(Restaurant&& move) {

		*this = std::move(move);
	}

	Restaurant& Restaurant::operator=(const Restaurant& copy) {
		if (this != &copy)
		{
			delete[] this->m_reservation;
			this->m_cnt = 0;
			this->m_reservation = new Reservation[copy.m_cnt];
			for (size_t i = 0; i < copy.m_cnt; i++)
			{
				this->m_reservation[i] = copy.m_reservation[i];
			}
			this->m_cnt = copy.m_cnt;
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& move) {

		if (this != &move)
		{
			delete[] this->m_reservation;
			this->m_reservation = move.m_reservation;
			move.m_reservation = nullptr;
			this->m_cnt = move.m_cnt;
			move.m_cnt = 0;
		}
		return *this;
	}

	ostream& operator<<(ostream& out, const Restaurant& restaurant) {

		out << "--------------------------" << endl;
		out << "Fancy Restaurant" << endl;
		out << "--------------------------" << endl;
		if (restaurant.m_reservation != nullptr)
		{
			for (size_t i = 0; i < restaurant.m_cnt; i++)
			{
				out << restaurant.m_reservation[i];
			}
		}
		else
		{
			out << "The object is empty!" << endl;
		}

		out << "--------------------------" << endl;
		return out;
	}

	Restaurant::~Restaurant() {

		delete[] m_reservation;
		m_reservation = nullptr;

	}
	
}