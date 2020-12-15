/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 03/10/2020
WS2P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include "RecordSet.h"
using namespace std;

namespace sdds {

	RecordSet::RecordSet() { //default constructor
		elements = nullptr; //setting member variables to an empty state
		count = 0;
	}


	RecordSet::RecordSet(const char* name) {
		int c = 0; 
		string buffer;
		ifstream file(name);

		while (!file.eof()) {
			getline(file, buffer, ' ');
			++c;
		}

		elements = new string[c];
		buffer = {};
		file.close();
		file.open(name);
		c = 0;
		while (getline(file, buffer, ' ')) {
			elements[c] = buffer;
			++c;
		}
		count = c;
	}

	RecordSet::RecordSet(const RecordSet& copied) { //copy constructor
		*this = copied;
	}

	RecordSet::RecordSet(RecordSet&& moved) {//move constructor
		*this = move(moved);
	}

	RecordSet& RecordSet::operator=(const RecordSet& copied) {//copy assignment

		if (this != &copied) {
			this->count = copied.count;
			this->elements = new string[copied.count];
			for (int i = 0; i < copied.count; ++i) {
				this->elements[i] = copied.elements[i];
			}
		}
		return *this;
	}

	RecordSet& RecordSet::operator=(RecordSet&& moved) {//move assignment

		if (this != &moved) {

			this->count = moved.count;
                        delete[] elements;
			elements = moved.elements;
			moved.elements = nullptr;
			moved.count = 0;
		}
		return *this;
	}


	size_t RecordSet::size() {
		return this->count;
	}

	string RecordSet::getRecord(size_t index) {

		if (index >= 0 && this->elements != nullptr) {
			return string(this->elements[index]);
		}
		else {
			return "";
		}
	}



	
	RecordSet::~RecordSet() {
		if (this->elements != nullptr)
		{
			delete[] elements;
			elements = nullptr;
		}
	}
}