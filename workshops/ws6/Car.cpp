/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 08/11/2020
WS6P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
I got help in Car constructor and trim + createInstance function
*/#include "Car.h"
#include "Racecar.h"
#include <iomanip>

using namespace std;

namespace sdds {

	void Car::trim(string& str) const {
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);

		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);

	}

	Car::Car(std::istream& is) {
		std::string substr = "";

		getline(is, m_maker, ',');
		trim(m_maker);


		getline(is, substr, ',');
		trim(substr);
		if (substr == "n" || substr == "N" || substr == "") {
			m_condition = "new";
		}

		else if (substr == "u" || substr == "U") {
			m_condition = "used";
		}
		else if (substr == "b" || substr == "B") {
			m_condition = "broken";
		}
		else {
			throw "Invalid Record!";

		}

		size_t start = 0;
		size_t begin = substr.find(',', start);
		std::getline(is, substr, ',');
		start = begin;
		begin = substr.find(',', start + 1);
		try {
			m_topSpeed = std::stod(substr.substr(start + 1, begin - start - 1));

		}
		catch (...) {
			throw "Invalid Record!";

		}

	}
	std::string Car::condition() const {
		return m_condition;
	}
	double Car::topSpeed() const {
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const {
		out << "| ";
		out << std::right;
		out.width(10);
		out << m_maker;
		out << " | ";
		out.width(6);
		out << std::left;
		out << m_condition;
		out << " | ";
		out.width(6);
		out << std::right;
		out << std::fixed;
		out << std::setprecision(2);
		out << topSpeed();
		out << " |";
	
	}
}