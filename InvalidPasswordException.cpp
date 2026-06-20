#include "InvalidPasswordException.h"

InvalidPasswordException::InvalidPasswordException():
	UserExceptions("Password must be at least 3 characters."){}
