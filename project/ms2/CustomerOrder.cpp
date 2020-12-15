// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include <algorithm>
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;


CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}


CustomerOrder::CustomerOrder(const std::string& str) {

	Utilities util;
	size_t next_pos = 0;
	bool more = false;

	if (str.empty()) 
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	else {

		m_name = util.extractToken(str, next_pos, more);
		if (more)
		{
			m_product = util.extractToken(str, next_pos, more);
		}

		std::string items = str.substr(next_pos, str.length() - next_pos);
		m_cntItem = (count(items.begin(), items.end(), util.getDelimiter())) + 1;

		m_lstItem = new Item* [m_cntItem];

		for (size_t i = 0; i < m_cntItem && more; i++)
		{
			m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
		}

		if (m_widthField < util.getFieldWidth())
		{
			m_widthField = util.getFieldWidth();
		}
	}
}


CustomerOrder::CustomerOrder(CustomerOrder& src) {
	throw "Error!";
}


CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	m_cntItem = 0;
	m_lstItem = nullptr;
	*this = move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
	if (this != &src)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		src.m_cntItem = 0;
		m_lstItem = src.m_lstItem;
		src.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::isOrderFilled() const {
	bool full = true;
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (!m_lstItem[i]->m_isFilled)
			full = false;
	}
	return full;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == itemName) {
			return m_lstItem[i]->m_isFilled;
		}
	}

	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {

	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				station.updateQuantity();
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else
			{
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	
	os << m_name << " - " << m_product << endl;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << setw(m_widthField) << left << m_lstItem[i]->m_itemName;
		if (m_lstItem[i]->m_isFilled)
			os << " - FILLED" << endl;
		else
			os << " - MISSING" << endl;
	}
}

CustomerOrder::~CustomerOrder() {

	if (m_lstItem == nullptr) {
		return;
	}

	for (unsigned int i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
}

