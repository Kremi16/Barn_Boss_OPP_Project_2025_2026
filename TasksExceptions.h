#pragma once
#include"BarnBossException.h"

class TasksExceptions:public BarnBossException
{
public:
	explicit TasksExceptions(const string& message);
};

