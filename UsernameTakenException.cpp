#include "UsernameTakenException.h"

UsernameTakenException::UsernameTakenException(const string& username):
	UserExceptions("Username '" + username + "' is already taken."){}
