#include "BarnBossException.h"

BarnBossException::BarnBossException(const string& message):message(message){}

const char* BarnBossException::what()const noexcept
{
	return message.c_str();
}
