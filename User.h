#pragma once
#include"Utils.h"
#include<memory>

class User
{
	friend class System;

private:
	static constexpr size_t MIN_LEN_PASSWORD = 3;
	static unsigned nextId;
	unsigned id;
	string username;
	string password;
	bool loggedIn = false;

public:
	User() = default;
	User(const string& username, const string& password);

	void login(const string& username, const string& password);
	void logout();
	void changePassword(const string& oldPassword, const string& newPassword);

	virtual void profileInfo()const = 0;
	virtual UserType getType()const = 0;
	virtual ~User() = default;

	unsigned getId()const;
	const string& getUsername()const;
	bool isLoggedIn()const;

	static unsigned getNextId();
	static void setNextId(unsigned id);
	static shared_ptr<User> createUser(const string& username, const string& password, const string& type);
};

