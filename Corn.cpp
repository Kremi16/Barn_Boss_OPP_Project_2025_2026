#include "Corn.h"

Corn::Corn():Crop(DEFAULT_REQUIRED_CYCLES){}

ProductType Corn::getProduct()const
{
	return ProductType::Corn;
}