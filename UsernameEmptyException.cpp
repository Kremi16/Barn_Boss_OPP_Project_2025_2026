#include "UsernameEmptyException.h"

UsernameEmptyException::UsernameEmptyException():
	UserExceptions("The username cannot be an empty string."){}
