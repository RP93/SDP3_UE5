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

int main()
{
	string const filename = "DriveData.txt"; 

	//create testfile
	ofstream Out(filename);
	srand((unsigned int)time(0));
	int Var = 0;
	int Delta = 8;
	for (int i = 1; i <= 400; i++)
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
	
	//test it
	RevolutionCounter* revCounter = new RevolutionCounter(filename);
	PKW* pkw = new PKW(revCounter);
	Speedometer* speedometer = new Speedometer(pkw);
	Milometer* milometer = new Milometer(pkw);
	
	for (int i = 0; i < 400; i++) {
		pkw->Process();
		Sleep(500);
	}

	delete milometer;
	delete speedometer;
	delete pkw;
	delete revCounter;

	return 0;
}