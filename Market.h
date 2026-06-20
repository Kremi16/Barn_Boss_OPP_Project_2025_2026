#pragma once
#include"MarketItem.h"
#include"Barn.h"
#include<vector>

class Market
{
private:
	vector<MarketItem> items;

public:
	Market();

	void openMarketCatalog()const;
	void buy(ProductType type, unsigned quantity, double& balance, Barn& barn);
	void sell(ProductType type, unsigned quantity, double& balance, Barn& barn);
	void restock(ProductType type, unsigned quantity);
	void changePrice(ProductType type, double newPrice);
	MarketItem* findItem(ProductType type);
	const MarketItem* findItem(ProductType type)const;

	unsigned getQuantity(ProductType type)const;
	double getPrice(ProductType type)const;

	void setQuantity(ProductType type, unsigned quantity);
	void setPrice(ProductType type, double price);
};

