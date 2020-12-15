/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/10/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
	
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& copy) {

		*this = copy;
	}


	ConfirmationSender::ConfirmationSender(ConfirmationSender&& move) noexcept{

		*this = std::move(move);
	}



	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {

		bool found = false;
		for (size_t i = 0; i < confirmCount && found == false; i++)
			if (&res == confirmReservation[i])
				found = true;
		if (found == false)
		{
			const sdds::Reservation** temp = nullptr;
			temp = new const Reservation * [confirmCount + 1];
			for (size_t i = 0; i < confirmCount; i++)
				temp[i] = confirmReservation[i];
			temp[confirmCount] = &res;

			++confirmCount;
			delete[] confirmReservation;
			confirmReservation = temp;
		}
		return *this;

	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < confirmCount; i++)
		{
			if (&res == confirmReservation[i])
			{
				confirmReservation[i] = nullptr;
			}
		}
		return *this;

	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& copy) {

		if (this != &copy)
		{
			this->confirmCount = 0;
			delete[] this->confirmReservation;
			this->confirmReservation = new const Reservation * [copy.confirmCount];
			for (size_t i = 0; i < copy.confirmCount; i++)
			{
				this->confirmReservation[i] = copy.confirmReservation[i];
			}
			this->confirmCount = copy.confirmCount;

		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& move) noexcept {

		if (this != &move)
		{
			delete[] confirmReservation;
			confirmReservation = move.confirmReservation;
			move.confirmReservation = nullptr;
			confirmCount = move.confirmCount;
			move.confirmCount = 0;
		}
		return *this;
	}



	ostream& operator<<(ostream& out, const ConfirmationSender& confirm) {


		if (confirm.confirmReservation != nullptr) {
			out << "--------------------------" << endl;
			out << "Confirmations to Send" << endl;
			out << "--------------------------" << endl;;
			for (size_t i = 0; i < confirm.confirmCount; i++) {
				if (confirm.confirmReservation[i] != nullptr) {
					out << *confirm.confirmReservation[i];
				}
			}
			out << "--------------------------"<<endl;
		}
		else {
			

			out << "--------------------------" <<endl;
			out << "Confirmations to Send"<<endl;
			out << "--------------------------" << endl;
			out << "The object is empty!"<<endl;
			out << "--------------------------"<<endl;
		}
		return out;
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] confirmReservation;
		confirmReservation = nullptr;
	}
}
