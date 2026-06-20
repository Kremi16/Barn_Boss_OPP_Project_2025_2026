#include "NegativeBalanceException.h"

NegativeBalanceException::NegativeBalanceException():
	UserExceptions("The balance must be greater than 0."){ }
