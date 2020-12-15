/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 11/10/2020
WS3P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds {

    template <typename T, unsigned int N>
    class SetSummable : public Set<T, N> {
    public:

        T accumulate(const std::string& filter) const
        {
            T sum(filter);
            for (size_t i = 0; i < this->size(); i++)
            {
                sum += (*this)[i];
            }
            return sum;
        }
    };


}

#endif // !
