#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Station.h"
#include "Station.h"
#include "Workstation.h"
#include "Workstation.h"
#include "CustomerOrder.h"
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Utilities.h"
#include "LineManager.h"
#include "LineManager.h"

using namespace std;

template<typename T>
static void loadFromFile(const char*, vector<T>&);
template<typename T>
static void loadFromFile(const char*, vector<T*>&);


int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	vector<Workstation*> theStations;
	vector<CustomerOrder> theOrders;

	Utilities::setDelimiter(',');
	loadFromFile(argv[1], theStations);
	Utilities::setDelimiter('|');
	loadFromFile(argv[2], theStations);

	cout << "========================================" << endl;
	cout << "=         Stations (summary)           =" << endl;
	cout << "========================================" << endl;
	for (const Workstation* station : theStations)
		station->Station::display(cout, false);
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=          Stations (full)             =" << endl;
	cout << "========================================" << endl;
	for (const Workstation* station : theStations)
		station->Station::display(cout, true);
	cout << endl << endl;

	//Select an object and verify all the functionality it working
	cout << "========================================" << endl;
	cout << "=          Manual Validation           =" << endl;
	cout << "========================================" << endl;
	cout << "getItemName(): " << theStations[0]->getItemName() << endl;
	cout << "getNextSerialNumber(): " << theStations[0]->getNextSerialNumber() << endl;
	cout << "getNextSerialNumber(): " << theStations[0]->getNextSerialNumber() << endl;
	cout << "getQuantity(): " << theStations[0]->getQuantity() << endl;
	theStations[0]->updateQuantity();
	cout << "getQuantity(): " << theStations[0]->getQuantity() << endl;
	cout << endl << endl;


	loadFromFile<CustomerOrder>(argv[3], theOrders);

	cout << "========================================" << endl;
	cout << "=                Orders                =" << endl;
	cout << "========================================" << endl;
	for (CustomerOrder& order : theOrders)
		order.display(std::cout);
	cout << endl << endl;

	LineManager lm(argv[4], theStations, theOrders);
	cout << "========================================" << endl;
	cout << "=       Display Stations (loaded)      =" << endl;
	cout << "========================================" << endl;
	lm.displayStations();
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=      Display Stations (ordered)      =" << endl;
	cout << "========================================" << endl;
	lm.displayStationsSorted();
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=           Filling Orders             =" << endl;
	cout << "========================================" << endl;
	while (!lm.run(cout));		//loop running the assembly line until complete
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=           Completed Orders           =" << endl;
	cout << "========================================" << endl;
	lm.displayCompletedOrders(cout);
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=          Inventory (full)            =" << endl;
	cout << "========================================" << endl;
	for (const Station* theItem : theStations)
		theItem->display(cout, true);
	cout << endl;

	// cleanup
	for (const Workstation* station : theStations)
		delete station;

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

template<typename T>
static void loadFromFile(const char* filename, vector<T*>& theCollection)
{
	ifstream file(filename);
	if (!file)
		throw string("Unable to open [") + filename + "] file.";

	string record;
	while (!file.eof())
	{
		std::getline(file, record);
		theCollection.push_back(new T(record));
	}

	file.close();
}