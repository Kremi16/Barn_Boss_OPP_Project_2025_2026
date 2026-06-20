#pragma once
#include"BarnBossException.h"

class MarketExceptions:public BarnBossException
{
public:
	explicit MarketExceptions(const string& message);
};

