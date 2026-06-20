#pragma once
#include<string>
using namespace std;

enum class ProductType {
    WheatSeed = 1,
    CornSeed,
    Chicken,
    Cow,
    Wheat,
    Corn,
    Egg,
    Milk
};

enum class UserType
{
    Player,
    TaskManager,
    MarketManager
};

class Utils
{
public:
    static string convertProductToString(ProductType type);
    static ProductType convertIdToProduct(unsigned id);
    static ProductType convertStringToProduct(const string& product);
};

