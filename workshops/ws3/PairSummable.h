/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 11/10/2020
WS3P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H


#include "Pair.h"

namespace sdds {

 template<typename K, typename V>
 class PairSummable : public Pair<K, V> {
 private:
	 static V init;
	 static size_t min;
 public:
	 PairSummable() :Pair<K, V>() {};
	 PairSummable(const K& key, const V& value = init) : Pair<K, V>(key, value) {
		 if (key.size() > min) {
			 min = key.size();
		 }
	 }

	 PairSummable& operator+=(const PairSummable& b) {

		 if (this != &b && Pair<K, V>::key() == b.key())

			 *this = PairSummable(Pair<K, V>::key(), Pair<K, V>::value() + b.value());

		 return *this;

	 }

	 virtual void display(std::ostream& os) const {
		 os.width(min);
		 os << std::left;
		 Pair<K, V>::display(os);
		 os << std::right;
	 };

 };

 template <typename K, typename V> size_t PairSummable<K, V>::min = 0;


 template <>
std::string PairSummable<std::string, std::string>::init = std::string("");


 template <>
 int PairSummable<std::string, int>::init = 0;


 template <>
PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& b)

 {

	 if (this != &b && Pair<std::string, std::string>::key() == b.key())

		 *this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string>::value() == "" ? b.value() : Pair<std::string, std::string>::value() + ", " + b.value());

	 return *this;

 }
}
#endif

