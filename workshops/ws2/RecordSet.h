/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 03/10/2020
WS2P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <string>

namespace sdds {

	class RecordSet {
	private:
	    std::string* elements;
		int count;
	public:
		RecordSet();
        RecordSet(const char* name);
		RecordSet(const RecordSet& copied);
		RecordSet(RecordSet&& moved);
		RecordSet& operator=(RecordSet&& moved);
		RecordSet& operator=(const RecordSet& copied);
		size_t size();
		std::string getRecord(size_t);
		~RecordSet();
	};
}

#endif