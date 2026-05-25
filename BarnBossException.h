#pragma once
#include<stdexcept>
#include<string>
using namespace std;

class BarnBossException:public exception
{
private:
	string message;

public:
	BarnBossException() = default;
	explicit BarnBossException(const string& message);

	const char* what()const noexcept;
};

