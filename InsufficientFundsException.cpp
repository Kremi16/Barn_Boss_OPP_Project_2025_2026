#include "InsufficientFundsException.h"

InsufficientFundsException::InsufficientFundsException(double required, double current)
    : MarketExceptions("Insufficient funds. Required: " + to_string(required) +
        ", Current: " + to_string(current)) { }