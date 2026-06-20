#include "Wheat.h"

Wheat::Wheat():Crop(DEFAULT_REQUIRED_CYCLES){}

ProductType Wheat::getProduct()const
{
	return ProductType::Wheat;
}