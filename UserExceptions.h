#pragma once
#include"BarnBossException.h"

class UserExceptions:public BarnBossException
{
public:
	UserExceptions() = default;
	explicit UserExceptions(const string& message);
};

