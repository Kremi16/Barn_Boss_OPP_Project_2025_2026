#pragma once
#include"UserExceptions.h"

class WrongPasswordException:public UserExceptions
{
public:
	WrongPasswordException();
};

