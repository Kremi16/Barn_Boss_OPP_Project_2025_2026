#pragma once
#include"UserExceptions.h"

class ManagerAlreadyExistsException:public UserExceptions
{
public:
	explicit ManagerAlreadyExistsException(const string& type);
};

