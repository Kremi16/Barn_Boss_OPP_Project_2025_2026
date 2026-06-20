#pragma once
#include"FarmExceptions.h"
#include"Utils.h"

class ItemNotFoundException:public FarmExceptions
{
public:
	explicit ItemNotFoundException(ProductType type);
};

