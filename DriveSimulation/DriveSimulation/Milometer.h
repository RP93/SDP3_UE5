///////////////////////////////////////////////////////////////////////////
// Workfile : Milometer.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Header for Milometer.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MILOMETER_H
#define MILOMETER_H

#include "Object.h"
#include "IObserver.h"
#include "WindowsDisplay.h"
#include "PKW.h"

unsigned int const cClock = 2;

class Milometer :
	public Object,
	public IObserver
{
public:
	//CTor
	Milometer(PKW* pkw);

	//virtual Destructor
	virtual ~Milometer();

	//virtual update function
	virtual void Update();

private:
	WindowsDisplay* mDigital;
	double mDistance;
	PKW* mPKW;
};

#endif