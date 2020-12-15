// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
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
	
	string token;

	if (next_pos <= str.length())
	{
		size_t location = str.find_first_of(m_delimiter, next_pos);
		if (location != string::npos)
		{
			token = str.substr(next_pos, location - next_pos);
			next_pos = location + 1;
		}
		else {
			token = str.substr(next_pos);
			next_pos = str.length() + 1;
		}

		if ((token.empty()) && (next_pos != str.length() + 1))
		{
			more = false;
			throw str + "<-- ERROR: Token Failure";
		}

		if (m_widthField < token.length())
		{
			m_widthField = token.length();
		}
		more = next_pos <= str.length();
	}

	return token;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}
