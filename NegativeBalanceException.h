#pragma once
#include"UserExceptions.h"

class NegativeBalanceException:public UserExceptions
{
public:
	NegativeBalanceException();
};

