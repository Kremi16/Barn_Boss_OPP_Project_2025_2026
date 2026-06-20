#include "InsufficientBarnStockException.h"

InsufficientBarnStockException::InsufficientBarnStockException(ProductType type, unsigned requested, unsigned available)
    : MarketExceptions("Not enough '" + Utils::convertProductToString(type) +
        "' in barn. Requested: " + to_string(requested) +
        ", Available: " + to_string(available)) { }
