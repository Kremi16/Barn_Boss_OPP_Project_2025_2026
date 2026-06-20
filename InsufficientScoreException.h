#pragma once
#include"FarmExceptions.h"

class InsufficientScoreException:public FarmExceptions
{
public:
	InsufficientScoreException(int required, int current);
};

