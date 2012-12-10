///////////////////////////////////////////////////////////////////////////
// Workfile : Speedometer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Implemantation of Speedometer
///////////////////////////////////////////////////////////////////////////

#include "Speedometer.h"

Speedometer::Speedometer(PKW* pkw) 
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

		mAnalog = new AnalogDisplay();
	}
	catch(std::string const& ex)
	{
		std::cerr << "Speedometer.cpp::Speedometer: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "Speedometer.cpp::Speedometer: Unknown Exception occured" << std::endl;
	}
}

Speedometer::~Speedometer() 
{
	mPKW->Detach(this);
	delete mAnalog;
}

void Speedometer::Update()
{
	mCurSpeed = mPKW->GetCurrentSpeed();

	mAnalog->SendValue((unsigned int)mCurSpeed);
}