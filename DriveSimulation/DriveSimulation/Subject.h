///////////////////////////////////////////////////////////////////////////
// Workfile : Subject.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of Subject.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Object.h"
#include "IObserver.h"
#include <list>

typedef std::list<IObserver*> TObservers;

class Subject :
	public Object
{
public:
	void Attach(IObserver*);
	void Detach(IObserver*);

protected:
	void NotifyObservers();

private:
	TObservers mObservers;
};

#endif