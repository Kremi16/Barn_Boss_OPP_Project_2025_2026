#pragma once
#include"MarketExceptions.h"

class InsufficientFundsException:public MarketExceptions
{
public:
	InsufficientFundsException(double required, double current);
};

