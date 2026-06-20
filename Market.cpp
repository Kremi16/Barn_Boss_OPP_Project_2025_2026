#include "Market.h"
#include"InsufficientBarnStockException.h"
#include"InsufficientFundsException.h"
#include"ProductNotFoundException.h"
#include"InsufficientStockException.h"
#include"InvalidPriceException.h"
#include<iostream>

Market::Market():
    items({
    {ProductType::WheatSeed, 20, 10.0},
    {ProductType::CornSeed, 20, 15.0},
    {ProductType::Chicken, 10, 25.0},
    {ProductType::Cow, 5, 50.0},
    {ProductType::Wheat, 20, 15.0},
    {ProductType::Corn, 20, 20.0},
    {ProductType::Egg, 15, 30.0},
    {ProductType::Milk, 10, 60.0}
    }) {}


void Market::buy(ProductType type, unsigned quantity, double& balance, Barn& barn)
{
    for (auto& item : items)
    {
        if (item.getProductType() == type)
        {
            if (item.getQuantity() < quantity)
            {
                throw InsufficientStockException(type, quantity, item.getQuantity());
            }

            double cost = item.getPrice() * quantity;

            if (balance < cost)
            {
                throw InsufficientFundsException(cost, balance);
            }

            item.setQuantity(item.getQuantity() - quantity);
            balance -= cost;

            barn.add(type, quantity);
            cout << "The purchase was successful!" << '\n';
            return;
        }
    }
    throw ProductNotFoundException(type);
}

void Market::sell(ProductType type, unsigned quantity, double& balance, Barn& barn)
{
    if (!barn.hasItem(type, quantity))
    {
        throw InsufficientBarnStockException(type, quantity, barn.getItemQuantity(type));
    }

    for (auto& item : items)
    {
        if (item.getProductType() == type)
        {
            barn.remove(type, quantity);

            double income = item.getPrice() * quantity;
            balance += income;

            item.setQuantity(item.getQuantity() + quantity);
            cout << "The sale was successful!" << '\n';
            return;
        }
    }

    throw ProductNotFoundException(type);
}

void Market::openMarketCatalog() const
{
    cout << "=== MARKET CATALOG ===\n";

    unsigned id = 1;

    for (const auto& item : items)
    {
        cout << id++ << '.';
        item.printItem();
    }
}

void Market::restock(ProductType type, unsigned quantity)
{
    for (auto& item : items)
    {
        if (item.getProductType() == type)
        {
            item.setQuantity(item.getQuantity() + quantity);
            return;
        }
    }
    throw ProductNotFoundException(type);
}

void Market::changePrice(ProductType type, double newPrice)
{
    if (newPrice <= 0)
    {
        throw InvalidPriceException();
    }

    for (auto& item : items)
    {
        if (item.getProductType() == type)
        {
            item.setPrice(newPrice);
            return;
        }
    }

    throw ProductNotFoundException(type);
}

MarketItem* Market::findItem(ProductType type) 
{
    auto it = find_if(items.begin(), items.end(), [&type](const MarketItem& item)
        {
            return item.getProductType() == type;
        });

    if (it == items.end())
    {
        return nullptr;
    }

    return &(*it);
}

const MarketItem* Market::findItem(ProductType type)const
{
    auto it = find_if(items.begin(), items.end(), [&type](const MarketItem& item)
        {
            return item.getProductType() == type;
        });

    if (it == items.end())
    {
        return nullptr;
    }

    return &(*it);
}


unsigned Market::getQuantity(ProductType type)const
{
    auto it = findItem(type);

    if (it == nullptr)
    {
        return 0;
    }

    return it->getQuantity();
}

double Market::getPrice(ProductType type)const
{
    auto it = findItem(type);

    if (it == nullptr)
    {
        return 0.0;
    }

    return it->getPrice();
}

void Market::setQuantity(ProductType type,unsigned quantity)
{
    auto it = findItem(type);
    if (it == nullptr)
    {
        return;
    }

    it->setQuantity(quantity);
}
void Market::setPrice(ProductType type,double price)
{
    auto it = findItem(type);
    if (it == nullptr)
    {
        return;
    }

    it->setPrice(price);
}