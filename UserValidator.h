#pragma once
#include"UsernameEmptyException.h"
#include"UsernameTakenException.h"
#include"InvalidPasswordException.h"
#include <string>
#include <vector>
using namespace std;

class UserValidator
{
private:
    static constexpr size_t MIN_LEN_PASSWORD = 3;
    static vector<string> usernames;

public:
    static void isUsernameValid(const string& username);
    static void registerUsername(const string& username);
    static void isPasswordValid(const string& password);
};