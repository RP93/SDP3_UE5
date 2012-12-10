///////////////////////////////////////////////////////////////////////////
// Workfile : Milometer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Implemantation of Milometer
///////////////////////////////////////////////////////////////////////////

#include "Milometer.h"

Milometer::Milometer(PKW* pkw) 
{
	try
	{
		if(pkw == 0)
		{
			std::string ex = "no valid pkw pointer";
			throw(ex);
		}
		mPKW = pkw;
		mPKW->Attach(this);
		mDistance = 0;
		mDigital = new DigitalDisplay();
	}
	catch(std::string const& ex)
	{
		std::cerr << "Milometer.cpp::Milometer: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "Milometer.cpp::Milometer: Unknown Exception occured" << std::endl;
	}
}

Milometer::~Milometer() 
{
	mPKW->Detach(this);
	delete mDigital;
}

void Milometer::Update()
{
	mDistance = ((mPKW->GetCurrentSpeed()/cHourSec)/cClock) + mDistance;

	mDigital->SendValue((unsigned int)mDistance);
}