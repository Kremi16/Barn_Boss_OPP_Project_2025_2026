#pragma once
#include"User.h"
#include"TaskBoard.h"

class TaskManager:public User
{
private:
    static bool exists; 

public:
    TaskManager() = default;
    TaskManager(const string& username, const string& password);
    ~TaskManager();

    void showTasks(const TaskBoard& taskBoard) const;
    void addTask(ProductType product, unsigned quantity,double rewardBalance, 
        unsigned rewardScore,TaskBoard& taskBoard);
    void removeTask(unsigned taskId, TaskBoard& taskBoard);
    void profileInfo() const override;
    UserType getType()const override;
};

