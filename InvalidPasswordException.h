#pragma once
#include"UserExceptions.h"

class InvalidPasswordException:public UserExceptions
{
public:
	InvalidPasswordException();
};

