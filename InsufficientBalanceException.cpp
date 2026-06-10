#include "InsufficientBalanceException.h"

InsufficientBalanceException::InsufficientBalanceException(unsigned required, unsigned current)
    : FarmExceptions("Insufficient balance. Required: " + std::to_string(required) +
        ", Current: " + std::to_string(current)) {}