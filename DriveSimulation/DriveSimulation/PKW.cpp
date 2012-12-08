///////////////////////////////////////////////////////////////////////////
// Workfile : PKW.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class PKW
///////////////////////////////////////////////////////////////////////////

#include "PKW.h"

PKW::PKW(RevolutionCounter* revCounter)
{
	if(revCounter == 0)
	{
		std::string ex = "no valid RevolutionCounter pointer";
		throw(ex);
	}
	mRevCounter = revCounter;
}

double PKW::GetCurrentSpeed()
{
	return ((mCurRev/cMinSec) * cWheelDiameter * PI * cHourSec);
}

void PKW::Process()
{
	mCurRev = mRevCounter->GetRevolutions();
	NotifyObservers();
}