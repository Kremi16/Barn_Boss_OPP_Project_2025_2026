#pragma once
#include"UserExceptions.h"

class InvalidCredentialsException:public UserExceptions
{
public:
	InvalidCredentialsException();
};

