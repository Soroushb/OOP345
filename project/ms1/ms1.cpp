#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Station.h"
#include "Station.h"
#include "Utilities.h"
#include "Utilities.h"

using namespace std;

static bool loadStations(const char*, vector<Station>&);

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	//**************//
	vector<Station> theStations;
	Utilities::setDelimiter(',');
	loadStations(argv[1], theStations);
	Utilities::setDelimiter('|');
	loadStations(argv[2], theStations);

	cout << "========================================" << endl;
	cout << "=         Stations (summary)           =" << endl;
	cout << "========================================" << endl;
	for (Station& theItem : theStations)
		theItem.display(cout, false);
	cout << endl << endl;

	cout << "========================================" << endl;
	cout << "=          Stations (full)             =" << endl;
	cout << "========================================" << endl;
	for (Station& theItem : theStations)
		theItem.display(cout, true);
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
	cout << endl;


	return 0;
}

bool loadStations(const char* filenameSt, vector<Station>& theStations)
{
	std::ifstream file(filenameSt);
	if (!file)
		throw string("Unable to open [") + filenameSt + "] file";

	// each line from the file represents an item;
	// read one at a time and add it to the inventory
	string theRecord;
	while (!file.eof())
	{
		std::getline(file, theRecord);
		Station newItem(theRecord);
		theStations.push_back(std::move(newItem));
	}
	file.close();
	return true;
}