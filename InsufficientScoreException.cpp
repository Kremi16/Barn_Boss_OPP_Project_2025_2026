#include "InsufficientScoreException.h"

InsufficientScoreException::InsufficientScoreException(int required, int current):
    FarmExceptions("Not enough score. Required: " + std::to_string(required) +
        ", Current: " + std::to_string(current)) {}