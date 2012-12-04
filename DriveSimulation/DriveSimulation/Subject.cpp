///////////////////////////////////////////////////////////////////////////
// Workfile : Subject.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class Subject
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include "Subject.h"

void Subject::Attach(IObserver* ob)
{
	//searches observer in observer list
	TObserversConstItor found =
		std::find(mObservers.begin(),
		mObservers.end(),ob);
	if (found == mObservers.end()){
		//observer not found in list
		mObservers.push_back(ob) ;
	}
}

void Subject::Detach(IObserver* ob)
{
	//searches observer in observer list
	TObserversConstItor foundObserver =
		find(mObservers.begin(),
		mObservers.end(), ob);
	if( foundObserver != mObservers.end() ) {
		//observer found in list
		mObservers.erase(foundObserver) ;
	}
}

void Subject::NotifyObservers()
{
	std::for_each(mObservers.begin(),mObservers.end(),[](IObserver* first)
	{
		first->Update();
	});
}