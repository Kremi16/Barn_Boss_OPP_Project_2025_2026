#include "MarketItem.h"
#include<print>
#include"InvalidPriceException.h"

MarketItem::MarketItem(ProductType type, unsigned quantity, double price) :
	type(type)
{
	if (price < 0.0)
	{
		throw InvalidPriceException();
	}

	this->quantity = quantity;
	this->price = price;
}

ProductType MarketItem::getProductType()const
{
	return type;
}

unsigned MarketItem::getQuantity()const
{
	return quantity;
}

double MarketItem::getPrice()const
{
	return price;
}

void MarketItem::setQuantity(unsigned quantity)
{
	this->quantity = quantity;
}

void MarketItem::setPrice(double price)
{
	this->price = price;
}

void MarketItem::printItem()const
{
	println("{} | Quantity: {} | Price: {}",Utils::convertProductToString(type), quantity, price);
}