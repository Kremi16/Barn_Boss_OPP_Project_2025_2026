#include "Chicken.h"

Chicken::Chicken():Animal(DEFAULT_REQUIRED_CYCLE){}

ProductType Chicken::getProduct()const
{
	return ProductType::Egg;
}
