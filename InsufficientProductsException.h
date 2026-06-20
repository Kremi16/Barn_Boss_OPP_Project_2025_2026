#pragma once
#include"TasksExceptions.h"
#include"Utils.h"

class InsufficientProductsException:public TasksExceptions
{
public:
	InsufficientProductsException(ProductType type, int required);
};

