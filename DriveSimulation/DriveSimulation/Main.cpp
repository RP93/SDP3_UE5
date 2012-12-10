///////////////////////////////////////////////////////////////////////////
// Workfile : Main.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Testdriver for DrivingSimulation
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <fstream>
#include <time.h>

#include <windows.h>
#include "WindowsDisplay.h"

#include "RevolutionCounter.h"
#include "PKW.h"
#include "Milometer.h"
#include "Speedometer.h"

using namespace std;

int GetRandVal( int Lo, int Hi)
{
	int Range = Hi - Lo + 1;
	int Num = rand() / (RAND_MAX + 1) * Range;
	return Lo + Num;
}

void TestCase(string const& filename, size_t RevEntries, string const& Header)
{
	cout << Header << endl;

	RevolutionCounter* revCounter = new RevolutionCounter(filename);
	PKW* pkw = new PKW(revCounter);
	Speedometer* speedometer = new Speedometer(pkw);
	Milometer* milometer = new Milometer(pkw);

	cout << "Process RevEntries: ... ";
	for (int i = 0; i < RevEntries; i++) {
		pkw->Process();
		Sleep(500);
	}
	cout << "Done" << endl;

	delete milometer;
	delete speedometer;
	delete pkw;
	delete revCounter;

	cout << endl << endl;
}

void FillFile(string const& filename, size_t RevEntries)
{
	try
	{
		//create testfile
		ofstream Out(filename);

		if(!Out.is_open())
		{
			std::string ex = "TestFile could not be opened";
			throw(ex);
		}

		srand((unsigned int)time(0));
		int Var = 0;
		int Delta = 8;
		for (int i = 1; i <= RevEntries; i++)
		{
			Out << GetRandVal(550 + Var, 580 + Var) << endl;
			Var += Delta;
			if (i % 50 == 0)
			{
				Delta = -Delta;
			}
		}
		Out << -1 << endl;
		Out.close();
	}
	catch(std::string const& ex)
	{
		std::cerr << "Main.cpp::FillFile: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "Main.cpp::FillFile: Unknown Exception occured" << std::endl;
	}
}

int main()
{
	string filename = "Not existing";
	size_t RevEntries = 1;

	TestCase(filename,RevEntries,"Testcase0: File does not exist.");

	filename = "EmptyFile.txt";
	RevEntries = 0;
	TestCase(filename,RevEntries,"Testcase1: Empty file without fill function.");

	filename = "EmptyFile2.txt";
	FillFile(filename,RevEntries);
	TestCase(filename,RevEntries,"Testcase2: Empty file with fill function.");

	filename = "InvalidDriveData.txt";
	RevEntries = 7;
	TestCase(filename,RevEntries,"Testcase3: File with invalid content.");

	filename = "SingleDriveData.txt";
	RevEntries = 1;
	FillFile(filename,RevEntries);
	TestCase(filename,RevEntries,"Testcase4: File with a single entry.");

	RevEntries = 3;
	TestCase(filename,RevEntries,"Testcase5: File with a single entry and too much Process calls.");

	filename = "DriveData.txt";
	RevEntries = 400;
	FillFile(filename,RevEntries);
	TestCase(filename,RevEntries,"Testcase6: File with multiple entries.");

	return 0;
}