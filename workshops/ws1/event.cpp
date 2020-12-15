/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 27/09/2020
WS1P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

unsigned long g_sysClock = 0;

namespace sdds {

	Event::Event(){
		desc = nullptr;
		start = 0;
	}

	void Event::display() const {

		static int counter = 0;
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		if (start >= 3600)
		{
			hours = start / 3600;
			minutes = (start % 3600) / 60;
			seconds = (start % 3600) % 60;
		}
		else if (start >= 60 && start < 3600) {
			minutes = start / 60;
			seconds = start % 60;
		}
		else {
			seconds = start;
		}
		cout << setw(3);
		if (desc != nullptr && desc[0] != '\0')
		{
			cout << ++counter << ". " << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " -> " << desc << endl;

		}
		else {
			cout << ++counter << ". " << "[ No Event ]" << endl;

		}

	}

	void Event::setDescription(const char* string) {

		this->start = ::g_sysClock;
	

		if (string != nullptr && string[0] != '\0')
		{
			if (desc != nullptr) {
				desc = nullptr;
			}
			desc = new char[strlen(string) + 1];
			strcpy(desc, string);
			
		}
		else {
			desc = nullptr;
			start = 0;
		}

	}

	Event::~Event(){
		if (desc == nullptr)
			delete[] desc;
	}

}