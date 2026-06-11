#include "InsufficientStockException.h"

InsufficientStockException::InsufficientStockException(ProductType type, unsigned requested, unsigned available)
    : MarketExceptions("Not enough stock for '" + Utils::convertProductToString(type) +
        "'. Requested: " + to_string(requested) +
        ", Available: " + to_string(available)) { }
