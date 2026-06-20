#include "MarketManager.h"
#include"ManagerAlreadyExistsException.h"
#include<print>

bool MarketManager::exists = false;

MarketManager::MarketManager(const std::string& username, const std::string& password):
	User(username,password)
{
	if (exists)
	{
		throw ManagerAlreadyExistsException("MarketManager");
	}
	exists = true;
}

MarketManager::~MarketManager()
{
	exists = false;
}

void MarketManager::openMarketCatalog(const Market& market) const
{
	market.openMarketCatalog();
}

void MarketManager::restock(unsigned productId, unsigned quantity, Market& market)
{
	market.restock(Utils::convertIdToProduct(productId), quantity);
}

void MarketManager::changePrice(unsigned productId, double newPrice, Market& market)
{
	market.changePrice(Utils::convertIdToProduct(productId), newPrice);
}

void MarketManager::profileInfo() const
{
	println("ID: {}", getId());
	println("Username: {}", getUsername());
	println("Type: MarketManager");
}

UserType MarketManager::getType()const
{
	return UserType::MarketManager;
}