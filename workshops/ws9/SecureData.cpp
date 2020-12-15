/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 26/11/2020
WS9
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.

		std::thread t1(std::bind(converter, text, key, nbytes / 2, Cryptor()));
		std::thread t2(std::bind(converter, text + nbytes / 2, key, nbytes - (nbytes / 2), Cryptor()));
		t1.join();
		t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{

			std::ofstream theFile(file, std::ios::binary | std::ios::trunc);
			if (!theFile) {
				throw std::string("\n***could not open the file***\n");
			}

			// TODO: write data into the binary file
			//         and close the file
			theFile.write(text, nbytes);
			theFile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading

		std::ifstream theFile(file, std::ios::in | std::ios::binary);
		if (!theFile) {
			throw std::string("\n***could not open the file***\n");
		}

		// TODO: - allocate memory here for the file content
		if (text)
			delete[] text;

		theFile.seekg(0, std::ios::end);
		nbytes = (int)theFile.tellg();

		text = new char[nbytes + 1];

		// TODO: - read the content of the binary file

		theFile.seekg(0, std::ios::beg);
		theFile.read(text, nbytes);
		theFile.close();

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}