#pragma once
#include"User.h"
#include"Market.h"

class MarketManager:public User
{
private:
    static bool exists;

public:
    MarketManager(const std::string& username, const std::string& password);
    ~MarketManager();

    void openMarketCatalog(const Market& market) const;
    void restock(unsigned productId, unsigned quantity, Market& market);
    void changePrice(unsigned productId, double newPrice, Market& market);

    void profileInfo() const override;
    UserType getType()const override;
};

