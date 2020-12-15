/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 03/10/2020
WS2P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>


namespace sdds {

	const int MAX = 7;
	class TimedEvents {

		int noRecords;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point finish;

		struct {
			std::string name{};
			std::string time{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* name);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& event);
	};
}
#endif