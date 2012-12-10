///////////////////////////////////////////////////////////////////////////
// Workfile : PKW.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class PKW
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "PKW.h"

PKW::PKW(RevolutionCounter* revCounter)
{
	try
	{
		if(revCounter == 0)
		{
			std::string ex = "no valid RevolutionCounter pointer";
			throw(ex);
		}
		mRevCounter = revCounter;

	}
	catch(std::string const& ex)
	{
		std::cerr << "PKW.cpp::PKW: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "PKW.cpp::PKW: Unknown Exception occured" << std::endl;
	}
}

double PKW::GetCurrentSpeed()
{
	return ((mCurRev/cMinSec) * cWheelDiameter * PI * cHourSec);
}

void PKW::Process()
{
	int tmp = mRevCounter->GetRevolutions();

	if (tmp >= 0)
	{
		mCurRev = tmp;
		NotifyObservers();
	}
}