/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/10/2020
WS4P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Reservation.h"
using namespace std;

namespace sdds {

	Reservation::Reservation(const std::string& res) {

		string   people, day, hour;
		string string = res;

		m_id = string.substr(0, string.find(':'));
		string.erase(0, string.find(':') + 1);
		m_name = string.substr(0, string.find(','));
		string.erase(0, string.find(',') + 1);
		m_email = string.substr(0, string.find(','));
		string.erase(0, string.find(',') + 1);
		people = string.substr(0, string.find(','));
		string.erase(0, string.find(',') + 1);
		day = string.substr(0, string.find(','));
		string.erase(0, string.find(',') + 1);
		hour = string.substr(0, string.find(','));
		m_id.erase(m_id.find_last_not_of(' ') + 1);
		m_id.erase(0, m_id.find_first_not_of(' '));
		m_name.erase(m_name.find_last_not_of(' ') + 1);
		m_name.erase(0, m_name.find_first_not_of(' '));
        m_email.erase(m_email.find_last_not_of(' ') + 1);
		m_email.erase(0, m_email.find_first_not_of(' '));
		m_email = "<" + m_email + ">";

        m_noPeople = stoi(people);
		m_day = stoi(day);
		m_hour = stoi(hour);
	}

	std::ostream& operator<<(std::ostream& out, const Reservation& reserve) {

		if (6 <= reserve.m_hour && reserve.m_hour <= 9)
		{
			out << "Reservation " << reserve.m_id << ": " << setw(10) << setfill(' ') << right << reserve.m_name << "  "<< setw(19) << setfill(' ') << left << reserve.m_email << "     Breakfast on day " << reserve.m_day << " @ " << reserve.m_hour << ":00 for " << reserve.m_noPeople << " people." << endl;

		}else if (11 <= reserve.m_hour && reserve.m_hour <= 15)
		{
			out << "Reservation " << reserve.m_id << ": " << setw(10) << setfill(' ')<< right   << reserve.m_name << "  " << setw(19) << setfill(' ')<< left << reserve.m_email << "     Lunch on day " << reserve.m_day << " @ " << reserve.m_hour << ":00 for " << reserve.m_noPeople << " people." << endl;

		}else if (17 <= reserve.m_hour && reserve.m_hour <= 21)
		{
			out << "Reservation " << reserve.m_id  << ": " << setw(10) << setfill(' ') << right << reserve.m_name << "  " << setw(19) << setfill(' ')<< left << reserve.m_email << "     Dinner on day " << reserve.m_day <<" @ " << reserve.m_hour << ":00 for " << reserve.m_noPeople << " people." << endl;

		}else
		{
			out << "Reservation " << reserve.m_id << ": " << setw(10) << setfill(' ') << right << reserve.m_name << "  " << setw(19) << setfill(' ')<< left  << reserve.m_email << "     Drinks on day " << reserve.m_day << " @ " << reserve.m_hour << ":00 for " << reserve.m_noPeople << " people." << endl;
		}

		return out;
	}
}