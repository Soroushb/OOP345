#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Station.h"
#include "Station.h"
#include "CustomerOrder.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Utilities.h"

using namespace std;

template<typename T>
static void loadFromFile(const char*, vector<T>&);

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	vector<Station>       theStations;
	vector<CustomerOrder> theOrders;

	{
		// Milestone 1
		Utilities::setDelimiter(',');
		loadFromFile<Station>(argv[1], theStations);
		Utilities::setDelimiter('|');
		loadFromFile<Station>(argv[2], theStations);

		cout << "========================================" << endl;
		cout << "=         Stations (summary)           =" << endl;
		cout << "========================================" << endl;
		for (Station& station : theStations)
			station.display(cout, false);
		cout << endl << endl;

		cout << "========================================" << endl;
		cout << "=          Stations (full)             =" << endl;
		cout << "========================================" << endl;
		for (Station& station : theStations)
			station.display(cout, true);
		cout << endl << endl;

		//Select an object and verify all the functionality it working
		cout << "========================================" << endl;
		cout << "=          Manual Validation           =" << endl;
		cout << "========================================" << endl;
		cout << "getItemName(): " << theStations[0].getItemName() << endl;
		cout << "getNextSerialNumber(): " << theStations[0].getNextSerialNumber() << endl;
		cout << "getNextSerialNumber(): " << theStations[0].getNextSerialNumber() << endl;
		cout << "getQuantity(): " << theStations[0].getQuantity() << endl;
		theStations[0].updateQuantity();
		cout << "getQuantity(): " << theStations[0].getQuantity() << endl;
		cout << endl << endl;
	}

	{
		// Milestone 2
		loadFromFile<CustomerOrder>(argv[3], theOrders);

		cout << "========================================" << endl;
		cout << "=                Orders                =" << endl;
		cout << "========================================" << endl;
		for (CustomerOrder& order : theOrders)
			order.display(std::cout);
		cout << endl << endl;

		//Select an object and verify all the functionality it working
		cout << "========================================" << endl;
		cout << "=          Manual Validation           =" << endl;
		cout << "========================================" << endl;
		cout << "CustomerOrders::display(): "; // Test #1
		theOrders[theOrders.size() - 1].display(cout);
		cout << endl;

		try
		{
			// copy constructor
			cout << "CustomerOrders::CustomerOrders(&): "; // Test #2
			CustomerOrder anOrder(theOrders[0]);
		}
		catch (...)
		{
			cout << "----> ERROR: Cannot make copies.";
			cout << endl << endl;
		}

		// move constructor
		cout << "CustomerOrders::CustomerOrders(&&): "; // Test #3
		CustomerOrder tmp(std::move(theOrders[theOrders.size() - 1]));
		theOrders.pop_back();
		tmp.display(cout);
		cout << endl;

		cout << "CustomerOrders::CustomerOrders(string): "; // Test #4
		string strRecord = "Chloe/Flight PC/CPU/GPU/Power Supply";
		Utilities::setDelimiter('/');
		CustomerOrder tmp2(strRecord);
		tmp2.display(cout);
		cout << endl;

		cout << "CustomerOrders::operator=(&&): "; // Test #5
		tmp2 = std::move(theOrders[theOrders.size() - 1]);
		theOrders.pop_back();
		tmp2.display(cout);
		cout << endl;

		cout << "CustomerOrders::fillItem()" << endl; // Test #6
		cout << "isOrderFilled(): "
			<< (tmp2.isOrderFilled() ? "FILLED" : "MISSING")
			<< endl;

		tmp2.fillItem(theStations[0], cout);
		cout << "isItemFilled(\"CPU\"): "
			<< (tmp2.isItemFilled("CPU") ? "FILLED" : "MISSING")
			<< endl;

		cout << "isOrderFilled(): "
			<< (tmp2.isOrderFilled() ? "FILLED" : "MISSING")
			<< endl;

		for (size_t i = 0; i < theStations.size(); i++)
			tmp2.fillItem(theStations[i], cout);

		cout << "isOrderFilled(): "
			<< (tmp2.isOrderFilled() ? "FILLED" : "MISSING")
			<< endl;
	}
	return 0;
}

template<typename T>
static void loadFromFile(const char* filename, vector<T>& theCollection)
{
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";

	string record;
	while (!file.eof())
	{
		std::getline(file, record);
		T elem(record);
		theCollection.push_back(std::move(elem));
	}

	file.close();
}