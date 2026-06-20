#include"User.h"
#include"UserValidator.h"
#include"Player.h"
#include"MarketManager.h"
#include"TaskManager.h"
#include"InvalidCredentialsException.h"
#include"WrongPasswordException.h"
#include"InvalidUserTypeException.h"
#include"UserAlreadyLoggedInException.h"

unsigned User::nextId = 0;

User::User(const string& username, const string& password) :
	id(++nextId)
{
	UserValidator::isUsernameValid(username);
	this->username = username;
	UserValidator::registerUsername(username);

	UserValidator::isPasswordValid(password);
	this->password = password;
}

void User::logout()
{
	loggedIn = false;
}

void User::changePassword(const string& oldPassword, const string& newPassword)
{
	if (oldPassword != password)
	{
		throw WrongPasswordException();
	}

	UserValidator::isPasswordValid(newPassword);
	password = newPassword;
}

unsigned User::getId()const
{
	return id;
}

const string& User::getUsername()const
{
	return username;
}

bool User::isLoggedIn()const
{
	return loggedIn;
}

void User::login(const string& username, const string& password)
{
	if (this->username!=username || this->password != password)
	{
		throw InvalidCredentialsException();
	}

	if (loggedIn)
	{
		throw UserAlreadyLoggedInException();
	}
	loggedIn = true;
}

unsigned User::getNextId()
{
	return nextId;
}

void User::setNextId(unsigned id)
{
	nextId = id;
}

shared_ptr<User> User::createUser(const string& username, const string& password,const string& type)
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