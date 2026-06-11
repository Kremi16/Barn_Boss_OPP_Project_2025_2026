#pragma once
#include"MarketExceptions.h"

class ProductOutOfStockException:public MarketExceptions
{
public:
	explicit ProductOutOfStockException(const string& productName);
};

