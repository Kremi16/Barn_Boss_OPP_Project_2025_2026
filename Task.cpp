#include "Task.h"
#include<print>

unsigned Task::nextId = 0;

Task::Task(ProductType product, unsigned quantity, double rewardBalance, unsigned rewardScore) :
	id(++nextId), product(product), quantity(quantity), rewardBalance(rewardBalance),
	rewardScore(rewardScore) {}

Task::Task(unsigned id, ProductType product, unsigned quantity,
	double rewardBalance, unsigned rewardScore)
	: id(id), product(product), quantity(quantity),
	rewardBalance(rewardBalance), rewardScore(rewardScore) {}

ProductType Task::getProductType()const
{
	return product;
}

unsigned Task::getQuantity()const
{
	return quantity;
}

double Task::getRewardBalance()const
{
	return rewardBalance;
}

unsigned Task::getRewardScore()const
{
	return rewardScore;
}

unsigned Task::getId()const
{
	return id;
}

void Task::printTask()const
{
	println("Deliver {} {} -> Reward: {} Balance, {} Score",
		quantity, Utils::convertProductToString(product), rewardBalance, rewardScore);
}

unsigned Task::getNextId()
{
	return nextId;
}

void Task::setNextId(unsigned id)
{
	nextId = id;
}