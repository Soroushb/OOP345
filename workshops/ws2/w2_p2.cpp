// Workshop 2 - Copy and Move Semantics
// w2.cpp

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "RecordSet.h"
#include "RecordSet.h" // intentional
#include "TimedEvents.h"
#include "TimedEvents.h" // intentional

using namespace sdds;


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc == 1)
	{
		std::cerr << "ERROR: Missing file name!\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << "ERROR: Too many arguments!\n";
		return 2;
	}

	sdds::TimedEvents t;
	{
		t.startClock();
		sdds::RecordSet a;
		t.stopClock();
		t.recordEvent("  0-arg Constructor");
		std::cout << "  0-arg Constructor - a.size = "
			<< std::setw(7) << a.size() << " records -> ";
		std::cout << std::setw(20) << "(a) Record    0: [" << a.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(a) Record  100: [" << a.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(a) Record 1000: [" << a.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(a) Record last: [" << a.getRecord(a.size() - 1) << "]\n\n";


		t.startClock();
		RecordSet b(argv[1]);
		t.stopClock();
		t.recordEvent("  1-arg Constructor");
		std::cout << "  1-arg Constructor - b.size = "
			<< std::setw(7) << b.size() << " records -> ";
		std::cout << std::setw(20) << "(b) Record    0: [" << b.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(b) Record  100: [" << b.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(b) Record 1000: [" << b.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(b) Record last: [" << b.getRecord(b.size() - 1) << "]\n\n";


		t.startClock();
		RecordSet c{ b };
		t.stopClock();
		t.recordEvent("  Copy Constructor");
		std::cout << "  Copy Constructor  - c.size = "
			<< std::setw(7) << c.size() << " records -> ";
		std::cout << std::setw(20) << "(c) Record    0: [" << c.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(c) Record  100: [" << c.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(c) Record 1000: [" << c.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(c) Record last: [" << c.getRecord(c.size() - 1) << "]\n\n";


		t.startClock();
		a = b;
		t.stopClock();
		t.recordEvent("  Copy Assignment");
		std::cout << "  Copy Assignment   - a.size = "
			<< std::setw(7) << a.size() << " records -> ";
		std::cout << std::setw(20) << "(a) Record    0: [" << a.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(a) Record  100: [" << a.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(a) Record 1000: [" << a.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(a) Record last: [" << a.getRecord(a.size() - 1) << "]\n\n";


		t.startClock();
		RecordSet d = std::move(a);
		t.stopClock();
		t.recordEvent("  Move Constructor");
		std::cout << "  Move Constructor  - d.size = "
			<< std::setw(7) << d.size() << " records -> ";
		std::cout << std::setw(20) << "(a) Record    0: [" << a.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(a) Record  100: [" << a.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(a) Record 1000: [" << a.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(a) Record last: [" << a.getRecord(a.size() - 1) << "]\n\n";
		std::cout << std::setw(70) << "(d) Record    0: [" << d.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(d) Record  100: [" << d.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(d) Record 1000: [" << d.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(d) Record last: [" << d.getRecord(d.size() - 1) << "]\n\n";


		t.startClock();
		a = std::move(d);
		t.stopClock();
		t.recordEvent("  Move Assignment");
		std::cout << "  Move Assignment   - a.size = "
			<< std::setw(7) << a.size() << " records -> ";
		std::cout << std::setw(20) << "(a) Record    0: [" << a.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(a) Record  100: [" << a.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(a) Record 1000: [" << a.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(a) Record last: [" << a.getRecord(a.size() - 1) << "]\n\n";
		std::cout << std::setw(70) << "(d) Record    0: [" << d.getRecord(0) << "]\n";
		std::cout << std::setw(70) << "(d) Record  100: [" << d.getRecord(100) << "]\n";
		std::cout << std::setw(70) << "(d) Record 1000: [" << d.getRecord(1000) << "]\n";
		std::cout << std::setw(70) << "(d) Record last: [" << d.getRecord(d.size() - 1) << "]\n";


		t.startClock();
	}
	t.stopClock();
	t.recordEvent("  Destructor");

	std::cout << t;
}