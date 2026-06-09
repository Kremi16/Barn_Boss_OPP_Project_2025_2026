#pragma once
#include"Crop.h"

class Wheat:public Crop
{
private:
	static constexpr unsigned DEFAULT_REQUIRED_CYCLES = 3;

public:
	Wheat();

	ProductType getProduct()const override;
};

