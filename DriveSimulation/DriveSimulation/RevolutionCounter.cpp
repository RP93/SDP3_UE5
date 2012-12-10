///////////////////////////////////////////////////////////////////////////
// Workfile : RevolutionCounter.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Implementation of class RevolutionCouter
///////////////////////////////////////////////////////////////////////////

#include "RevolutionCounter.h"
#include <string>
#include <iostream>
#include <sstream>

RevolutionCounter::RevolutionCounter(std::string const& filename)
{
	try
	{
		mSensorFile.open(filename);
		if(!mSensorFile.is_open())
		{
			std::string ex = "error in open file";
			throw(ex);
		}
	}
	catch(std::string const& ex)
	{
		std::cerr << "RevolutionCounter.cpp::RevolutionCounter: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "RevolutionCounter.cpp::RevolutionCounter: Unknown Exception occured" << std::endl;
	}
}

RevolutionCounter::~RevolutionCounter()
{
	mSensorFile.close();
}

int RevolutionCounter::GetRevolutions()
{
	try
	{
		std::string help;
		getline(mSensorFile,help);

		if((help == "-1") || (help == ""))
		{
			std::string ex = "end of data";
			throw(ex);
		}

		unsigned int rev = 0;
		if(std::istringstream(help) >> rev)
		{
			return rev;
		}
		else
		{
			std::string ex = "conversion string to int failed";
			throw(ex);
		}
	}
	catch(std::string const& ex)
	{
		std::cerr << "RevolutionCounter.cpp::GetRevolutions: " << ex << std::endl;
		return -1;
	}
	catch(...)
	{
		std::cerr << "RevolutionCounter.cpp::GetRevolutions: Unknown Exception occured" << std::endl;
		return -1;
	}
}