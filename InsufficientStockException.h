#pragma once
#include"MarketExceptions.h"
#include"Utils.h"

class InsufficientStockException:public MarketExceptions
{
public:
	InsufficientStockException(ProductType type, unsigned requested, unsigned available);
};

