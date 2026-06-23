#pragma once
#include"User.h"

class UserFactory
{
public:
	static shared_ptr<User> createUser(const string& username, const string& password, const string& type);
};

