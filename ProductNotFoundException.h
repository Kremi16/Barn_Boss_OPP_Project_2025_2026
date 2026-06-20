#pragma once
#include"MarketExceptions.h"
#include"Utils.h"

class ProductNotFoundException:public MarketExceptions
{
public:
	explicit ProductNotFoundException(ProductType type);
};

