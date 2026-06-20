#pragma once
#include"UserExceptions.h"

class UsernameTakenException:public UserExceptions
{
public:
	explicit UsernameTakenException(const string& username);
};

