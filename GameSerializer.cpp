#include "GameSerializer.h"

void GameSerializer::save(const System& system, const string& filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("File cannot be opened.");
    }

    file << system.users.size() << "\n";
    for (const auto& user : system.users)
    {
        file << static_cast<int>(user->getType()) << "\n";
        file << user->getId() << "\n";
        file << user->getUsername() << "\n";
        file << user->password << "\n";

        if (user->getType() == UserType::Player)
        {
            auto player = static_pointer_cast<Player>(user);
            file << player->checkBalance() << "\n";
            file << player->checkScore() << "\n";
            file << player->getCycles() << "\n";

            for (unsigned i = 1; i <= system.PRODUCTS_SIZE; i++)
            {
                file << player->getBarn().getItemQuantity(static_cast<ProductType>(i)) << "\n";
            }

            const auto& cropland = player->getFarm().getCropland();
            file << cropland.size() << "\n";
            for (const auto& crop : cropland)
            {
                file << static_cast<int>(crop->getProduct()) << "\n";
                file << crop->getCurrentCycles() << "\n";
            }

            const auto& farmland = player->getFarm().getFarmland();
            file << farmland.size() << "\n";
            for (const auto& animal : farmland)
            {
                file << static_cast<int>(animal->getProduct()) << "\n";
                file << animal->getCurrentCycles() << "\n";
            }

            file << player->getFarm().getCroplandCapacity() << "\n";
            file << player->getFarm().getFarmlandCapacity() << "\n";
        }
    }
}

void GameSerializer::load(System& system, const string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return;
    }

    system.users.clear();

    size_t userCount;
    file >> userCount;
    file.ignore();

    for (size_t i = 0; i < userCount; ++i)
    {
        int type;
        unsigned id;
        std::string username, password;
        file >> type >> id;
        file.ignore();
        std::getline(file, username);
        std::getline(file, password);

        if (type == static_cast<int>(UserType::Player))
        {
            double balance;
            unsigned score, cycles;
            file >> balance >> score >> cycles;

            auto player = std::make_shared<Player>(username, password, balance, score);
            player->setCycles(cycles);

            for (unsigned i = 1; i <= system.PRODUCTS_SIZE; i++)
            {
                unsigned quantity;
                file >> quantity;
                if (quantity > 0)
                {
                    player->getBarn().add(static_cast<ProductType>(i), quantity);
                }
            }

            size_t cropCount;
            file >> cropCount;
            for (size_t i = 0; i < cropCount; i++)
            {
                int productType;
                unsigned currentCycles;
                file >> productType >> currentCycles;
                player->getFarm().addCropFromSave(
                    static_cast<ProductType>(productType), currentCycles);
            }

            size_t animalCount;
            file >> animalCount;
            for (size_t i = 0; i < animalCount; i++)
            {
                int productType;
                unsigned currentCycles;
                file >> productType >> currentCycles;
                player->getFarm().addAnimalFromSave(
                    static_cast<ProductType>(productType), currentCycles);
            }

            size_t cropCap, farmCap;
            file >> cropCap >> farmCap;
            player->getFarm().setCapacities(cropCap, farmCap);
            system.users.push_back(player);
        }
        else if (type == static_cast<int>(UserType::TaskManager))
        {
            system.users.push_back(std::make_shared<TaskManager>(username, password));
        }
        else if (type == static_cast<int>(UserType::MarketManager))
        {
            system.users.push_back(std::make_shared<MarketManager>(username, password));
        }
    }

    for (unsigned i = 1; i <= 8; ++i)
    {
        unsigned quantity;
        double price;
        file >> quantity >> price;
        system.market.setQuantity(static_cast<ProductType>(i), quantity);
        system.market.setPrice(static_cast<ProductType>(i), price);
    }

    size_t taskCount;
    file >> taskCount;
    for (size_t i = 0; i < taskCount; ++i)
    {
        unsigned id, quantity, rewardScore;
        double rewardBalance;
        int productType;
        file >> id >> productType >> quantity >> rewardBalance >> rewardScore;
        system.taskBoard.addTaskFromSave(id, static_cast<ProductType>(productType),
            quantity, rewardBalance, rewardScore);
    }

    unsigned userNextId, taskNextId;
    file >> userNextId >> taskNextId;
    User::setNextId(userNextId);
    Task::setNextId(taskNextId);
    file.close();
}

