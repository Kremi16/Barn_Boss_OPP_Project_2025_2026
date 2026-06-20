#include "ManagerAlreadyExistsException.h"

ManagerAlreadyExistsException::ManagerAlreadyExistsException(const string& type):
	UserExceptions("A " + type + " already exists.") {}

