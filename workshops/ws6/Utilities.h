/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 08/11/2020
WS6P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
I got help in Car constructor and trim + createInstance function
*/
#ifndef SDDS_Utilities_H
#define SDDS_Utilities_H
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in);
};


#endif