/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 03/10/2020
WS2P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "TimedEvents.h"

using namespace std;

namespace sdds
{
	TimedEvents::TimedEvents() {
		noRecords = 0;
	}

	void TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock()
	{
		finish = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* name)
	{


		if (noRecords < MAX)
		{
			this->events[noRecords].name = name;
			this->events[noRecords].time = "nanoseconds";
			this->events[noRecords].duration = chrono::duration_cast<chrono::nanoseconds>(finish - start);
			noRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& out, const TimedEvents& event)
	{
		out << "--------------------------" << endl;
		out << "Execution Times:" << endl;
		out << "--------------------------" << endl;

		for (int i = 0; i < event.noRecords; i++)
		{
			out.width(20);
			out.setf(ios::left);
			out << event.events[i].name << ' ';
			out.unsetf(ios::left);
			out.width(12);
			out.setf(ios::right);
			out	<< event.events[i].duration.count() << ' '
				<< event.events[i].time << endl;
			out.unsetf(ios::right);
		}

		out << "--------------------------" << endl;
		return out;
	}
}