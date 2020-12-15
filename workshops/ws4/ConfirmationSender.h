/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/10/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace sdds {
	
	class ConfirmationSender {
		const sdds::Reservation** confirmReservation = nullptr;
		size_t confirmCount = 0;	
	public:
		ConfirmationSender() {};
		ConfirmationSender(const ConfirmationSender& copy);
		ConfirmationSender(ConfirmationSender&& move) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender& operator=(const ConfirmationSender& copy);
		ConfirmationSender& operator=(ConfirmationSender&& move) noexcept;
		friend std::ostream& operator<<(std::ostream& out, const ConfirmationSender& confirm);
		~ConfirmationSender();
	};
}

#endif


