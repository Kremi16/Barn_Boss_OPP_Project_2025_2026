#pragma once
#include"FarmObject.h"

class Animal:public FarmObject
{
public:
	Animal();
	explicit Animal(unsigned requiredCycles);

	virtual ~Animal() = default;
};

