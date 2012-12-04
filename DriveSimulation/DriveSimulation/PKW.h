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

class PKW :
	public Subject
{
public:
	PKW(RevolutionCounter*);

	double GetCurrentSpeed();
	void Process();

private:
	unsigned int mCurRev;
	RevolutionCounter* mRevCounter;
};

#endif