// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-18
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include<iostream>
#include <string>
#include "Station.h"


struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
private:
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(const std::string& str);
	CustomerOrder(CustomerOrder& src);
	CustomerOrder(CustomerOrder&& src) noexcept;
	CustomerOrder& operator=(CustomerOrder&& src) noexcept;
	~CustomerOrder();
	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif