#pragma once
#include"FarmObject.h"

class Crop:public FarmObject
{
public:
	Crop();
	explicit Crop(unsigned requiredCycles);

	virtual ~Crop() = default;
};

