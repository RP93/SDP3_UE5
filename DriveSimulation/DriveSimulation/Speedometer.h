///////////////////////////////////////////////////////////////////////////
// Workfile : Speedometer.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Header for Speedometer.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include "Object.h"
#include "IObserver.h"
#include "WindowsDisplay.h"
#include "PKW.h"

class Speedometer :
	public Object,
	public IObserver
{
public:
	//CTor
	Speedometer(PKW* pkw);

	//virtual Destructor
	virtual ~Speedometer();

	//virtual update function
	virtual void Update();

private:
	WindowsDisplay* mAnalog;
	double mCurSpeed;
	PKW* mPKW;
};

#endif