// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <algorithm>
#include "Utilities.h"

using namespace std;


char Utilities::m_delimiter = ' ';

void Utilities::setFieldWidth(size_t newWidth) {

	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {

	return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	string tempStr;

	size_t start = next_pos;
	next_pos = str.find(m_delimiter, start);
	if (next_pos == string::npos) {

		tempStr = str.substr(start);
		m_widthField = max(tempStr.length(), m_widthField);
		more = true;

	}
	else if (start == next_pos)
	{
		more = false;
		throw "No token between delimiters!";
	}
	else {

		tempStr = str.substr(start, next_pos - start);
		m_widthField = max(tempStr.length(), m_widthField);
		more = true;
	}

	next_pos = next_pos + 1;

	return tempStr;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
