#include "System.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

System::System() 
{
    GameSerializer::load(*this, SAVE_FILE);

    if (taskBoard.isEmpty()) 
    {
        taskBoard.addTask(ProductType::Wheat, 5, 50.0, 10, false);
        taskBoard.addTask(ProductType::Milk, 3, 120.0, 20, false);
    }
}


std::shared_ptr<Player> System::currentPlayer() const 
{
    auto locked = currentUser.lock();
    if (locked && locked->getType() == UserType::Player)
    {
        return static_pointer_cast<Player>(locked);
    }
    return nullptr;
}

std::shared_ptr<TaskManager> System::currentTaskManager() const 
{
    auto locked = currentUser.lock();
    if (locked && locked->getType() == UserType::TaskManager)
    {
        return static_pointer_cast<TaskManager>(locked);
    }
    return nullptr;
}

std::shared_ptr<MarketManager> System::currentMarketManager() const 
{
    auto locked = currentUser.lock();
    if (locked && locked->getType() == UserType::MarketManager)
    {
        return static_pointer_cast<MarketManager>(locked);
    }
    return nullptr;
}

void System::advanceCycles() 
{
    if (auto player = currentPlayer())
    {
        player->advanceCycles();
    }
}

void System::registerUser(const std::string& username, const std::string& password,const std::string& type) 
{
    try 
    {
        auto user = User::createUser(username, password, type);
        users.push_back(user);
        cout << "User registered successfully!\n";
    }
    catch (const exception& e) 
    {
        std::cout << e.what() << "\n";
    }
}

void System::login(const std::string& username, const std::string& password) 
{
    auto locked = currentUser.lock();
    if (locked) 
    {
        cout << "Already logged in. Please logout first.\n";
        return;
    }

    for (auto& user : users) 
    {
        if (user->getUsername() == username) 
        {
            try 
            {
                user->login(username, password);
                currentUser = user;
                cout << "Welcome, " << username << "!\n";
            }
            catch (const exception& e) 
            {
                cout << e.what() << "\n";
            }
            return;
        }
    }
    std::cout << "User not found.\n";
}


void System::logout() 
{
    auto locked = currentUser.lock();
    if (!locked) 
    { 
        cout << "No user logged in.\n";
        return;
    }

    locked->logout();
    currentUser.reset();
}

void System::profileInfo() const 
{
    auto locked = currentUser.lock();
    if (!locked) 
    { 
        cout << "No user logged in.\n";
        return; 
    }
    locked->profileInfo();
}

void System::changePassword(const std::string& oldPass, const std::string& newPass)
{
    auto locked = currentUser.lock();
    if (!locked) 
    { 
        cout << "No user logged in.\n"; 
        return; 
    }

    try 
    {
        locked->changePassword(oldPass, newPass);
        cout << "Password changed successfully!\n";
    }
    catch (const exception& e) 
    {
        std::cout << e.what() << "\n";
    }
}

void System::checkBalance() const 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return;
    }
    cout << "Current Balance: " << currentPlayer()->checkBalance() << "\n";
}

void System::checkScore() const 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }
    cout << "Current Score: " << currentPlayer()->checkScore() << "\n";
}

void System::checkBarn() const 
{
    if (!currentPlayer())
    { 
        cout << "Not a player.\n"; 
        return; 
    }
    currentPlayer()->checkBarn();
}

void System::checkFarm() const 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }
    currentPlayer()->checkFarm();
}

void System::expandCropland() 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }

    try 
    {
        currentPlayer()->expandCropland();
        advanceCycles();
    }
    catch (const std::exception& e) 
    { 
        cout << e.what() << "\n"; 
    }
}

void System::expandFarmland() 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }

    try 
    {
        currentPlayer()->expandFarmland();
        advanceCycles();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n"; 
    }
}

void System::sowPlant(unsigned seedId) 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n";
        return; 
    }

    try 
    {
        currentPlayer()->sowPlant(seedId);
        advanceCycles();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n";
    }
}

void System::addAnimal(unsigned animalId) 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n";
        return; 
    }

    try 
    {
        currentPlayer()->addAnimal(animalId);
        advanceCycles();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n";
    }
}

void System::harvest() 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }

    try 
    {
        currentPlayer()->harvest();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n";
    }
}

void System::buyItem(unsigned productId, unsigned quantity) 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }

    try 
    {
        currentPlayer()->buyItem(productId, quantity, market);
        advanceCycles();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n";
    }
}

void System::sellItem(unsigned productId, unsigned quantity) 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }

    try 
    {
        currentPlayer()->sellItem(productId, quantity, market);
        advanceCycles();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n"; 
    }
}

void System::showTaskBoard() const 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n"; 
        return; 
    }
    currentPlayer()->showTaskBoard(taskBoard);
}

void System::completeTask(unsigned taskId) 
{
    if (!currentPlayer()) 
    { 
        cout << "Not a player.\n";
        return; 
    }

    try 
    {
        currentPlayer()->completeTask(taskId, taskBoard);
        advanceCycles();
    }
    catch (const exception& e) 
    { 
        cout << e.what() << "\n"; 
    }
}

void System::showScoreboard() const 
{
    scoreboard.showScoreboard(users);
}

void System::showTasks() const 
{
    if (!currentTaskManager()) 
    { 
        cout << "Not a TaskManager.\n"; 
        return; 
    }
    currentTaskManager()->showTasks(taskBoard);
}

void System::addTask(ProductType product, unsigned quantity,
    double rewardBalance, unsigned rewardScore) 
{
    if (!currentTaskManager()) 
    {
        cout << "Not a TaskManager.\n"; 
        return;
    }
    currentTaskManager()->addTask(product, quantity, rewardBalance, rewardScore, taskBoard);
}

void System::removeTask(unsigned taskId) 
{
    if (!currentTaskManager()) 
    { 
        cout << "Not a TaskManager.\n"; 
        return; 
    }
    currentTaskManager()->removeTask(taskId, taskBoard);
}

void System::openMarketCatalog() const 
{
    if (currentPlayer())
    {
        currentPlayer()->openMarketCatalog(market);
    }
    else if (currentMarketManager())
    {
        currentMarketManager()->openMarketCatalog(market);
    }
    else
    {
        cout << "Not logged in.\n";
    }
}

void System::restock(unsigned productId, unsigned quantity) 
{
    if (!currentMarketManager()) 
    {
        cout << "Not a MarketManager.\n"; 
        return; 
    }

    try 
    {
        currentMarketManager()->restock(productId, quantity, market);
    }
    catch (const exception& e)
    { 
        cout << e.what() << "\n"; 
    }
}

void System::changePrice(unsigned productId, double newPrice) {
    if (!currentMarketManager()) 
    { 
        cout << "Not a MarketManager.\n"; 
        return; 
    }

    try 
    {
        currentMarketManager()->changePrice(productId, newPrice, market);
    }
    catch (const exception& e) 
    {
        cout << e.what() << "\n"; 
    }
}

void System::run() {
    cout << "========================================\n";
    cout << "            BARN BOSS\n";
    cout << "========================================\n";

    string line;
    while (true)
    {
        cout << "> ";
        if (!getline(std::cin, line))
        {
            break;
        }

        if (line == "exit")
        {
            try
            {
                GameSerializer::save(*this, SAVE_FILE);
                cout << "Game saved successfully.\nGoodbye!\n";
            }
            catch (const exception& e)
            {
                cout << "Save failed: " << e.what() << "\n";
            }
            break;
        }
        handleCommand(line);
    }
}

void System::handleCommand(const string& line) 
{
    istringstream ss(line);
    string cmd;
    ss >> cmd;

    if (cmd == "register") 
    {
        string username, password, type;
        ss >> username >> password >> type;
        registerUser(username, password, type);
        cout << '\n';
    }
    else if (cmd == "login") 
    {
        string username, password;
        ss >> username >> password;
        login(username, password);
        cout << '\n';
    }
    else if (cmd == "logout")
    {
        logout();
        cout << '\n';
    }
    else if (cmd == "profileInfo")
    {
        profileInfo();
        cout << '\n';
    }
    else if (cmd == "checkBalance")
    {
        checkBalance();
        cout << '\n';
    }
    else if (cmd == "checkScore")
    {
        checkScore();
    }
    else if (cmd == "checkBarn")
    {
        checkBarn();
        cout << '\n';
    }
    else if (cmd == "checkFarm")
    {
        checkFarm();
        cout << '\n';
    }
    else if (cmd == "expandCropland")
    {
        expandCropland();
        cout << '\n';
    }
    else if (cmd == "expandFarmland")
    {
        expandFarmland();
        cout << '\n';
    }
    else if (cmd == "harvest")
    {
        harvest();
        cout << '\n';
    }
    else if (cmd == "showTaskBoard")
    {
        showTaskBoard();
        cout << '\n';
    }
    else if (cmd == "showTasks")
    {
        showTasks();
        cout << '\n';
    }
    else if (cmd == "showScoreboard")
    {
        showScoreboard();
        cout << '\n';
    }
    else if (cmd == "openMarketCatalog")
    {
        openMarketCatalog();
        cout << '\n';
    }
    else if (cmd == "changePassword") 
    {
        std::string oldPass, newPass;
        ss >> oldPass >> newPass;
        changePassword(oldPass, newPass);
        cout << '\n';
    }
    else if (cmd == "sowPlant") 
    {
        unsigned id; 
        ss >> id;
        sowPlant(id);
        cout << '\n';
    }
    else if (cmd == "addAnimal") 
    {
        unsigned id; 
        ss >> id;
        addAnimal(id);
        cout << '\n';
    }
    else if (cmd == "buyItem") 
    {
        unsigned id, quantity; 
        ss >> id >> quantity;
        buyItem(id, quantity);
        cout << '\n';
    }
    else if (cmd == "sellItem") 
    {
        unsigned id, quantity;
        ss >> id >> quantity;
        sellItem(id, quantity);
        cout << '\n';
    }
    else if (cmd == "completeTask") 
    {
        unsigned id; 
        ss >> id;
        completeTask(id);
        cout << '\n';
    }
    else if (cmd == "addTask") 
    {
        string product; 
        unsigned quantity, score;
        double balance;
        ss >> product >> quantity >> balance >> score;
        addTask(Utils::convertStringToProduct(product), quantity, balance, score);
        cout << '\n';
    }
    else if (cmd == "removeTask") 
    {
        unsigned id; 
        ss >> id;
        removeTask(id);
        cout << '\n';
    }
    else if (cmd == "restock") 
    {
        unsigned id, quantity;
        ss >> id >> quantity;
        restock(id, quantity);
        cout << '\n';
    }
    else if (cmd == "changePrice") 
    {
        unsigned id; double price; 
        ss >> id >> price;
        changePrice(id, price);
        cout << '\n';
    }
    else 
    {
        cout << "Unknown command.\n";
        cout << '\n';
    }
}
