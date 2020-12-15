// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <iostream>

class Station {
private:
	int m_id{ 0 };
	std::string m_name{};
	std::string m_description{};
	int m_nextSerial{ 0 };
	int m_currentItems{ 0 };
	static size_t m_widthField;
	static size_t id_generator;
public:
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif