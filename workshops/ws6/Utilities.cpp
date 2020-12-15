/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 08/11/2020
WS6P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
I got help in Car constructor and trim + createInstance function
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"


using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		char ch = '\0';
		char ch2 = '\0';

		std::string substr = "";
		getline(in, substr);
		std::stringstream ss(substr);
		ss >> ch >> ch2;
		if (ss) {
			if (ch == 'c' || ch == 'C') {
				return new Car(ss);
			}
			else if (ch == 'r' || ch == 'R') {
				return new Racecar(ss);
			}
			else
				throw ch;
		}
		else
			return nullptr;
	}

}