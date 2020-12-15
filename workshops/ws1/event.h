/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 27/09/2020
WS1P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned long g_sysClock;

namespace sdds {

	class Event {
	private:
		char* desc;;
		size_t start;
	public:
		Event();
		void display() const;
		void setDescription(const char* string);
		~Event();
	};
}

#endif