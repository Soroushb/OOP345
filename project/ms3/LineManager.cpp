// Name: Soroush Bahrami
// Seneca Student ID: 152499182
// Seneca email: sbahrami7@myseneca.ca
// Date of completion: 2020-11-25
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

LineManager::LineManager(const std::string& file, std::vector<Workstation*>& stations, std::vector<CustomerOrder>& orders) {

	Utilities util;

	std::ifstream ifs(file);
	if (!ifs.is_open())
	{
		throw string("ERROR:  Failed to open the file [") + file + "].";
	}

	std::string record = "";
	std::string CurrentStation = "";
	std::string NextStation = "";
	size_t next_pos;
	bool more;

	while (!ifs.eof())
	{
		next_pos = 0;
		std::getline(ifs, record);

		CurrentStation = util.extractToken(record, next_pos, more);
		if (more)
		{
			NextStation = util.extractToken(record, next_pos, more);
		}
		else {
			NextStation = "";
		}

		for (size_t i = 0; i < stations.size(); i++)
		{

			if (stations[i]->getItemName() == CurrentStation)
			{
				for (size_t x = 0; x < stations.size(); x++) {

					if (stations[x]->getItemName() == NextStation)
					{
						stations[i]->setNextStation(*stations[x]);
						break;
					}
				}

				if (m_firstStation == nullptr)
				{
					m_firstStation = stations[i];
				}
			}

		}
	}

	ifs.close();

	for (size_t y = 0; y < orders.size(); y++)
		ToBeFilled.push_back(std::move(orders[y]));
	m_cntCustomerOrder = ToBeFilled.size();
	AssemblyLine = stations;
}

bool LineManager::run(std::ostream& os) {

	static size_t cnt = 0;
	cout << "Line Manager Iteration: " << ++cnt << endl;
	if (!ToBeFilled.empty())
	{
		*m_firstStation += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t x = 0; x < AssemblyLine.size(); x++)
		AssemblyLine[x]->runProcess(os);

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->moveOrder();

		CustomerOrder order;
		if (AssemblyLine[i]->getIfCompleted(order))
		{
			Completed.push_back(std::move(order));
		}
	}

	if (Completed.size() == m_cntCustomerOrder)
		return true;
	else
		return false;

}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (auto i = Completed.begin(); i != Completed.end(); i++)
	{
		(*i).display(os);
	}
}

void LineManager::displayStations() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {

	const Workstation* iter = m_firstStation;

	while (iter != nullptr)
	{
		iter->display(std::cout);
		iter = iter->getNextStation();
	}
}
