#include "UserValidator.h"
#include<stdexcept>

vector<string> UserValidator::usernames;

void UserValidator::isUsernameValid(const std::string& username)
{
	if (username.empty())
	{
		throw UsernameEmptyException();
	}

	auto it = find_if(usernames.begin(), usernames.end(),
		[&username](const string& u)
		{
			return username == u;
		});

	if (it == usernames.end())
	{
		return;
	}
	throw UsernameTakenException(username);
}

void UserValidator::registerUsername(const std::string& username)
{
	usernames.push_back(username);
}

void UserValidator::isPasswordValid(const string& password)
{
	if (password.size() < MIN_LEN_PASSWORD)
	{
		throw InvalidPasswordException();
	}
}
