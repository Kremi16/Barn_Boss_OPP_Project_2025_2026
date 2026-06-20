#pragma once
#include"MarketExceptions.h"

class InvalidPriceException:public MarketExceptions
{
public:
	InvalidPriceException();
};

