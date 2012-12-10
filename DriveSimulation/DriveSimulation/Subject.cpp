///////////////////////////////////////////////////////////////////////////
// Workfile : Subject.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class Subject
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <string>
#include "Subject.h"

void Subject::Attach(IObserver* ob)
{
	try
	{
		if(ob == 0)
		{
			std::string ex = "no valid observer pointer";
			throw(ex);
		}
		//searches observer in observer list
		TObserversConstItor found =
			std::find(mObservers.begin(),
			mObservers.end(),ob);
		if (found == mObservers.end()){
			//observer not found in list
			mObservers.push_back(ob) ;
		}
	}
	catch(std::string const& ex)
	{
		std::cerr << "Subject.cpp::Attach: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "Subject.cpp::Attach: Unknown Exception occured" << std::endl;
	}
}

void Subject::Detach(IObserver* ob)
{
	try
	{
		if(ob == 0)
		{
			std::string ex = "no valid observer pointer";
			throw(ex);
		}
		//searches observer in observer list
		TObserversConstItor foundObserver =
			find(mObservers.begin(),
			mObservers.end(), ob);
		if(foundObserver != mObservers.end() ) {
			//observer found in list
			mObservers.erase(foundObserver) ;
		}
	}
	catch(std::string const& ex)
	{
		std::cerr << "Subject.cpp::Detach: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "Subject.cpp::Detach: Unknown Exception occured" << std::endl;
	}
}

void Subject::NotifyObservers()
{
	std::for_each(mObservers.begin(),mObservers.end(),[](IObserver* first)
	{
		first->Update();
	});
}