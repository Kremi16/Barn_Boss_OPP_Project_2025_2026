#include "WrongPasswordException.h"

WrongPasswordException::WrongPasswordException()
	: UserExceptions("Current password is incorrect.") {}

