#pragma once
#include"Animal.h"

class Chicken:public Animal
{
private:
	static constexpr unsigned DEFAULT_REQUIRED_CYCLE = 3;

public:
	Chicken();

	ProductType getProduct()const override;
};

