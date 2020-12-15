/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 11/10/2020
WS3P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

namespace sdds {

	template<typename K, typename V>
	class Pair{
		K m_key;
		V m_value;
	public:
		Pair() {};
		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		};
		const K& key() const {
			return m_key;
		};
		const V& value() const {
			return m_value;
		};
		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
			pair.display(os);
			return os;
		}
		

	};
}

#endif