#include "ProductNotFoundException.h"

ProductNotFoundException::ProductNotFoundException(ProductType type)
    : MarketExceptions("Product " + Utils::convertProductToString(type)
        + " not found in market.") { }