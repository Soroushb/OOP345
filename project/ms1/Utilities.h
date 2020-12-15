// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

class Utilities {

private:
	size_t m_widthField = 1;
	static char m_delimiter;
public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};

#endif