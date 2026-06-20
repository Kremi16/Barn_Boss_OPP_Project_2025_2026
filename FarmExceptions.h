#pragma once
#include"BarnBossException.h"

class FarmExceptions:public BarnBossException
{
public:
	explicit FarmExceptions(const string& message);
};

