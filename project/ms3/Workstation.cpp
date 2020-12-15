// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-25
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Workstation.h"
#include "Utilities.h"

using namespace std;

Workstation::Workstation(const std::string& str) : Station(str){
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (m_orders.empty())
	{
		return;
	}
	
	m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder() {
	if (m_orders.empty())
	{
		return false;
	}

	if (m_orders.front().isItemFilled(this->getItemName()) && m_pNextStation)
	{
		*m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}

	return false;
}

void Workstation::setNextStation(Workstation& station) {
	m_pNextStation = &station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& src) {
	if (m_orders.empty() == false && m_orders.back().isOrderFilled())
	{
		src = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}

	return false;
}

void Workstation::display(std::ostream& os) const {

	if (m_pNextStation)
	{
		os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;
	}
	else {
		os << getItemName() << " --> END OF LINE" << endl;
	}
}

Workstation& Workstation::operator+=(CustomerOrder&& src) {

	m_orders.push_back(std::move(src));

	return *this;
}