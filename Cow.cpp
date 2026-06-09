#include "Cow.h"

Cow::Cow():Animal(DEFAULT_REQUIRED_CYCLES){}

ProductType Cow::getProduct()const
{
	return ProductType::Milk;
}

