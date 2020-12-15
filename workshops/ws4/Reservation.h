/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/10/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>
namespace sdds {

	class Reservation {
		std::string m_id = "";
		std::string m_name = "";
		std::string m_email= "";
		int m_noPeople = 0;
		size_t m_day = 0;
		size_t m_hour = 0;
	public:
		Reservation() {};
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& reserve);
	};
}

#endif