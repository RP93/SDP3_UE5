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
#include <iterator>

typedef std::list<IObserver*> TObservers;
typedef TObservers::const_iterator TObserversConstItor;

class Subject :
	public Object
{
public:
	//adds an observer to observer list
	void Attach(IObserver* ob);

	//removes an observer from observer list
	void Detach(IObserver* ob);

protected:
	//notify all observers in observer list
	void NotifyObservers();

private:
	TObservers mObservers;
};

#endif