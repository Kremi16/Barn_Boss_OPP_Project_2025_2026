#pragma once
#include"Animal.h"

class Cow:public Animal
{
private:
	static constexpr unsigned DEFAULT_REQUIRED_CYCLES = 5;

public:
	Cow();

	ProductType getProduct()const override;
};

