#pragma once
#include"FarmExceptions.h"

class InsufficientBalanceException:public FarmExceptions
{
public:
	InsufficientBalanceException(unsigned required, unsigned current);
};

