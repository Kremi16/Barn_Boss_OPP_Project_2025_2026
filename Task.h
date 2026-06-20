#pragma once
#include"Utils.h"

class Task
{
private:
    static unsigned nextId;
    unsigned id;
    ProductType product;
    unsigned quantity;

    double rewardBalance;
    unsigned rewardScore;

public:
    Task() = default;
    Task(ProductType product, unsigned quantity, double rewardBalance, unsigned rewardScore);
    Task(unsigned id, ProductType product, unsigned quantity, double rewardBalance, unsigned rewardScore);

    unsigned getId()const;
    ProductType getProductType()const;
    unsigned getQuantity()const;
    double getRewardBalance()const;
    unsigned getRewardScore()const;

    void printTask()const;
    static unsigned getNextId();
    static void setNextId(unsigned id);
};

