///////////////////////////////////////////////////////////////////////////
// Workfile : RevolutionCounter.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 6.11.2012
// Description : Header of RevolutionCounter.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef REVOLUTIONCOUNTER_H
#define REVOLUTIONCOUNTER_H

#include <string>
#include <fstream>
#include "Object.h"

class RevolutionCounter :
	public Object
{
public:
	RevolutionCounter(std::string const& filename);
	~RevolutionCounter();
	
	unsigned int GetRevolutions();
	
private:
	std::ifstream mSensorFile;
};

#endif