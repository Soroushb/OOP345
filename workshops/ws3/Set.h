/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 11/10/2020
WS3P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template<typename T, unsigned int N>
	class Set {
		T arr[N];
		unsigned int num = 0;
	public:
		size_t size() const {
			return num;
		}
		const T& operator[](size_t idx) const {
			return arr[idx];
		}
		void operator+=(const T& item) {
			if (num < N)
			{
				arr[num] = item;
				num++;
			}
		}
	};
}

#endif