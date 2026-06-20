#include "ProductOutOfStockException.h"

ProductOutOfStockException::ProductOutOfStockException(const string& productName)
	: MarketExceptions("Product '" + productName + "' is out of stock.") {}
