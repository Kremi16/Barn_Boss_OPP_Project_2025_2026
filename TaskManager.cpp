#include "TaskManager.h"
#include"ManagerAlreadyExistsException.h"
#include<print>

bool TaskManager::exists = false;

TaskManager::TaskManager(const string& username, const string& password):
	User(username,password)
{
	if (exists)
	{
		throw ManagerAlreadyExistsException("TaskManager");
	}
	exists = true;
}

TaskManager::~TaskManager()
{
	exists = false;
}

void TaskManager::showTasks(const TaskBoard& taskBoard) const
{
	taskBoard.showTasks();
}

void TaskManager::addTask(ProductType product, unsigned quantity, double rewardBalance,
	unsigned rewardScore, TaskBoard& taskBoard)
{
	taskBoard.addTask(product, quantity, rewardBalance, rewardScore);
}

void TaskManager::removeTask(unsigned taskId, TaskBoard& taskBoard)
{
	taskBoard.removeTask(taskId);
}

void TaskManager::profileInfo() const
{
	println("ID: {}", getId());
	println("Username: {}", getUsername());
	println("Type: TaskManager");
}

UserType TaskManager::getType()const
{
	return UserType::TaskManager;
}