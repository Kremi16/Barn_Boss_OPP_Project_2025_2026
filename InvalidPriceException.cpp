#include "InvalidPriceException.h"

InvalidPriceException::InvalidPriceException()
	: MarketExceptions("Price must be greater than 0.") { }
