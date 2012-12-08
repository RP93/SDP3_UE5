///////////////////////////////////////////////////////////////////////////
// Workfile : PKW.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of PKW.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef PKW_H
#define PKW_H

#include "Subject.h"
#include "RevolutionCounter.h"

double const cHourSec = 3.6;
double const cMinSec = 60;
double const cWheelDiameter = 0.6;
double const PI = 3.141592653589793238462;

class PKW :
	public Subject
{
public:
	PKW(RevolutionCounter* revCounter);

	double GetCurrentSpeed();
	void Process();

private:
	unsigned int mCurRev;
	RevolutionCounter* mRevCounter;
};

#endif