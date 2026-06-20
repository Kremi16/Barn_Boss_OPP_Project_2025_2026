#pragma once
#include"Crop.h"

class Corn:public Crop
{
private:
	static constexpr unsigned DEFAULT_REQUIRED_CYCLES = 4;

public:
	Corn();

	ProductType getProduct()const override;
};

