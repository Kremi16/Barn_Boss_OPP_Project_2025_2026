#pragma once
#include"MarketExceptions.h"
#include"Utils.h"

class InsufficientBarnStockException:public MarketExceptions
{
public:
	InsufficientBarnStockException(ProductType type, unsigned requested, unsigned available);
};

