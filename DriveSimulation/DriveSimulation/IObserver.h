///////////////////////////////////////////////////////////////////////////
// Workfile : Observer.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 04.12.2012
// Description : Observer interface
///////////////////////////////////////////////////////////////////////////

#ifndef OBSERVER_H
#define OBSERVER_H

//observer interface
class IObserver
{
public:
	virtual void Update() = 0 ;
	virtual ~IObserver() {};
};

#endif