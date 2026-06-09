#include "Barn.h"
#include<stdexcept>
#include<iostream>

Barn::Barn():items(8,0){}

unsigned Barn::toIndex(ProductType type) const
{
    return static_cast<unsigned>(type) - 1;
}


void Barn::add(ProductType type, unsigned quantity)
{
	items[toIndex(type)] += quantity;
}

void Barn::remove(ProductType type, unsigned quantity)
{
	if (!hasItem(type, quantity))
	{
		throw runtime_error("Not enough items in barn.");
	}
	items[toIndex(type)] -= quantity;
}

bool Barn::hasItem(ProductType type, unsigned quantity) const
{
	return items[toIndex(type)] >= quantity;
}

unsigned Barn::getItemQuantity(ProductType type) const
{
	return items[toIndex(type)];
}

void Barn::print()const
{
	cout << "=== BARN ===\n";

	for (size_t i = 0; i < items.size(); i++)
	{
		ProductType type = static_cast<ProductType>(i+1);
		cout << Utils::convertProductToString(type) << ": " << items[i] << '\n';
	}
}