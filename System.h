#pragma once
#include"Player.h"
#include"TaskManager.h"
#include"MarketManager.h"
#include"ScoreBoard.h"

class System
{
private:
    static constexpr size_t PRODUCTS_SIZE = 8;
    static constexpr const char* SAVE_FILE = "BarnBoss.txt";

    vector<shared_ptr<User>> users;
    Market market;
    TaskBoard taskBoard;
    ScoreBoard scoreboard;
    weak_ptr<User> currentUser;

    shared_ptr<Player> currentPlayer() const;
    shared_ptr<TaskManager> currentTaskManager() const;
    shared_ptr<MarketManager> currentMarketManager() const;

    void advanceCycles();

public:
    System();
    void run();

private:
    void registerUser(const std::string& username,const std::string& password,const std::string& type);
    void login(const std::string& username, const std::string& password);

    void logout();
    void profileInfo() const;
    void changePassword(const std::string& oldPass, const std::string& newPass);

    void checkBalance() const;
    void checkScore() const;
    void checkBarn() const;
    void checkFarm() const;
    void expandCropland();
    void expandFarmland();
    void sowPlant(unsigned seedId);
    void addAnimal(unsigned animalId);
    void harvest();
    void buyItem(unsigned productId, unsigned quantity);
    void sellItem(unsigned productId, unsigned quantity);
    void showTaskBoard() const;
    void completeTask(unsigned taskId);
    void showScoreboard() const;

    void showTasks() const;
    void addTask(ProductType product, unsigned quantity,double rewardBalance, unsigned rewardScore);
    void removeTask(unsigned taskId);

    void openMarketCatalog() const;
    void restock(unsigned productId, unsigned quantity);
    void changePrice(unsigned productId, double newPrice);

    void save() const;
    void load();

    void handleCommand(const std::string& line);
};

