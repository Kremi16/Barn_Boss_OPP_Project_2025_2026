#include "UserFactory.h"
#include"Player.h"
#include"TaskManager.h"
#include"MarketManager.h"
#include"InvalidUserTypeException.h"

shared_ptr<User> UserFactory::createUser(const string& username, const string& password, const string& type)
{
	if (type == "Player")
	{
		return make_shared<Player>(username, password);
	}
	else if (type == "TaskManager")
	{
		return make_shared<TaskManager>(username, password);
	}
	else if (type == "MarketManager")
	{
		return make_shared<MarketManager>(username, password);
	}

	throw InvalidUserTypeException();
}