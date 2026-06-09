#include "FarmObject.h"

FarmObject::FarmObject():currentCycles(0),requiredCycles(0){}

FarmObject::FarmObject(unsigned requiredCycles):currentCycles(0),requiredCycles(requiredCycles){}

void FarmObject::tick()
{
	currentCycles++;
}

bool FarmObject::isReady()const
{
	return currentCycles >= requiredCycles;
}

unsigned FarmObject::getCurrentCycles()const
{
	return currentCycles;
}

unsigned FarmObject::getRequiredCycles()const
{
	return requiredCycles;
}