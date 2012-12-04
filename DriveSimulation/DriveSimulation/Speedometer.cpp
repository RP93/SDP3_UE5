///////////////////////////////////////////////////////////////////////////
// Workfile : Speedometer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Implemantation of Speedometer
///////////////////////////////////////////////////////////////////////////

#include "Speedometer.h"

Speedometer::Speedometer(PKW* pkw) 
{
	mPKW = pkw;
	mPKW->Attach(this);

	mAnalog = new AnalogDisplay();
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