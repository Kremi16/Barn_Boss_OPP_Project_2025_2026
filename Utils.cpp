#include "Utils.h"
#include<stdexcept>

string Utils::convertProductToString(ProductType type)
{
    switch (type)
    {
    case ProductType::Wheat: return "Wheat";
    case ProductType::Corn: return "Corn";
    case ProductType::Egg: return "Egg";
    case ProductType::Milk: return "Milk";
    case ProductType::WheatSeed: return "Wheat Seed";
    case ProductType::CornSeed: return "Corn Seed";
    case ProductType::Chicken: return "Chicken";
    case ProductType::Cow: return "Cow";
    default: return "Unknown";
    }
}

ProductType Utils::convertIdToProduct(unsigned id)
{
    switch (id)
    {
    case 1: return ProductType::WheatSeed;
    case 2: return ProductType::CornSeed;
    case 3: return ProductType::Chicken;
    case 4: return ProductType::Cow;
    case 5: return ProductType::Wheat;
    case 6: return ProductType::Corn;
    case 7: return ProductType::Egg;
    case 8: return ProductType::Milk;

    default:
        throw invalid_argument("Invalid product id");
    }
}

ProductType Utils::convertStringToProduct(const string& product)
{
    if (product == "WheatSeed")
    {
        return ProductType::WheatSeed;
    }
    else if (product == "CornSeed")
    {
        return ProductType::CornSeed;
    }
    else if (product == "Wheat")
    {
        return ProductType::Wheat;
    }
    else if (product == "Corn")
    {
        return ProductType::Corn;
    }
    else if (product == "Milk")
    {
        return ProductType::Milk;
    }
    else if (product == "Egg")
    {
        return ProductType::Egg;
    }
    else if (product == "Chicken")
    {
        return ProductType::Chicken;
    }
    else if (product == "Cow")
    {
        return ProductType::Cow;
    }
    else
    {
        throw invalid_argument("Invalid product.");
    }
}
