///////////////////////////////////////////////////////////////////////////
// Workfile : Milometer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Implemantation of Milometer
///////////////////////////////////////////////////////////////////////////

#include "Milometer.h"

Milometer::Milometer(PKW* pkw) 
{
	mPKW = pkw;
	mPKW->Attach(this);

	mDigital = new DigitalDisplay();
}

Milometer::~Milometer() 
{
	mPKW->Detach(this);
	delete mDigital;
}

void Milometer::Update()
{
	mDistance = (mPKW->GetCurrentSpeed()/cHourSec)/cClock;

	mDigital->SendValue((unsigned int)mDistance);
}