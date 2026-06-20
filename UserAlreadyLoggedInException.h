#pragma once
#include"UserExceptions.h"

class UserAlreadyLoggedInException:public UserExceptions
{
public:
	UserAlreadyLoggedInException();
};

