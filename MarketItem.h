#pragma once
#include"Utils.h"

class MarketItem
{
private:
    ProductType type;
    unsigned quantity;
    double price;

public:
    MarketItem() = default;
    MarketItem(ProductType type, unsigned quantity, double price);

    ProductType getProductType()const;
    unsigned getQuantity()const;
    double getPrice()const;

    void setQuantity(unsigned quantity);
    void setPrice(double price);

    void printItem()const;
};

