#include "InsufficientProductsException.h"

InsufficientProductsException::InsufficientProductsException(ProductType type, int required)
    : TasksExceptions("Not enough '" + Utils::convertProductToString(type) +
        "' to complete task. Required: " + to_string(required)) {}
