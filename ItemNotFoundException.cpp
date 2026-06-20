#include "ItemNotFoundException.h"

ItemNotFoundException::ItemNotFoundException(ProductType type)
	: FarmExceptions("Item not found in barn: " + Utils::convertProductToString(type)) {}