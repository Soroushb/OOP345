// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "Utilities.h"
#include "Station.h"

using namespace std;

size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station(const std::string& str) {

	m_id = id_generator;

	Utilities utilit;
	size_t next_pos = 0;

	bool more = true;

	try {
		m_name = utilit.extractToken(str, next_pos, more);
		if (more)
		{
			m_nextSerial = stoi(utilit.extractToken(str, next_pos, more));
		}
		if (more)
		{
			m_currentItems = stoi(utilit.extractToken(str, next_pos, more));
		}
		m_widthField = max(utilit.getFieldWidth(), m_widthField);
		m_description = utilit.extractToken(str, next_pos, more);
	}
	catch (string& error) {
		cout << error;
	}
	id_generator++;
}

const std::string& Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	return m_nextSerial++;
}

unsigned int Station::getQuantity() const {
	return m_currentItems;
}

void Station::updateQuantity() {
	m_currentItems--;
	if (m_currentItems < 0) {
		m_currentItems = 0;
	}
}

void Station::display(std::ostream& os, bool full) const {

	os << right << "[" << setw(3) << setfill('0') << m_id + 1 << "]" << left << " Item: " << setw(m_widthField) << setfill(' ') << m_name << right << " [" << setw(6) << setfill('0') << m_nextSerial << "]" << left;

	if (full) {
		os << " Quantity: " << setw(m_widthField) << setfill(' ') << m_currentItems << " Description: " << m_description << endl;
	}
	else {
		os << endl;
	}

}
