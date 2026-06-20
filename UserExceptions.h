#pragma once
#include"BarnBossException.h"

class UserExceptions:public BarnBossException
{
public:
	explicit UserExceptions(const string& message);
};

