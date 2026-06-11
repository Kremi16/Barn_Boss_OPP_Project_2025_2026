#pragma once
#include"Task.h"
#include"Barn.h"
#include<vector>

class TaskBoard
{
private:
	vector<Task> tasks;

public:
    TaskBoard() = default;

    void showTasks() const;
    void addTask(ProductType product, unsigned quantity, double balance, unsigned score);
    bool removeTask(unsigned id);
    Task* getTask(unsigned id);
    void completeTask(unsigned id, Barn& barn, double& balance, unsigned& score);
    bool isEmpty()const;
    const vector<Task>& getTasks()const;
    void addTaskFromSave(unsigned id, ProductType product, unsigned quantity,
        double rewardBalance, unsigned rewardScore);
};

