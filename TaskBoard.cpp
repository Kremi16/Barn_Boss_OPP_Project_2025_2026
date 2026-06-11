#include "TaskBoard.h"
#include"TaskNotFoundException.h"
#include"InsufficientProductsException.h"
#include<iostream>

void TaskBoard::showTasks() const
{
    if (tasks.empty()) 
    {
        cout << "No available tasks.\n";
        return;
    }

    cout << "=== TASK BOARD ===" << '\n';
    unsigned id = 1;
    for (const auto& task : tasks)
    {
        cout << id++ << '.';
        task.printTask();
    }
}

void TaskBoard::completeTask(unsigned id, Barn& barn, double& balance, unsigned& score)
{
    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        if (it->getId() == id)
        {
            if (!barn.hasItem(it->getProductType(), it->getQuantity()))
            {
                throw InsufficientProductsException(it->getProductType(), it->getQuantity());
            }

            barn.remove(it->getProductType(), it->getQuantity());

            balance += it->getRewardBalance();
            score += it->getRewardScore();

            tasks.erase(it);
            return;
        }
    }
    throw TaskNotFoundException(id);
}

void TaskBoard::addTask(ProductType product, unsigned quantity, double balance, unsigned score)
{
    tasks.emplace_back(product, quantity, balance, score);
    cout << "Task added succesfully." << '\n';
}

bool TaskBoard::removeTask(unsigned id)
{
    size_t oldSize = tasks.size();
    erase_if(tasks, [&id](const Task& t)
        {
            return t.getId() == id;
        });

    if (oldSize != tasks.size())
    {
        cout << "Task removed successfully." << '\n';
        return true;
    }
    return false;
}

Task* TaskBoard::getTask(unsigned id)
{
    auto it = find_if(tasks.begin(), tasks.end(), [&id](const Task& t)
        {
            return t.getId() == id;
        });

    if (it == tasks.end())
    {
        return nullptr;
    }

    return &(*it);
}

bool TaskBoard::isEmpty()const
{
    return tasks.empty();
}

const vector<Task>& TaskBoard::getTasks()const
{
    return tasks;
}

void TaskBoard::addTaskFromSave(unsigned id, ProductType product, unsigned quantity,
    double rewardBalance, unsigned rewardScore)
{
    tasks.emplace_back(id,product, quantity, rewardBalance, rewardScore);
}