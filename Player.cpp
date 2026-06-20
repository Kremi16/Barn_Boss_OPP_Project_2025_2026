#include "Player.h"
#include"NegativeBalanceException.h"
#include<print>

Player::Player(const string& username, const string& password):
	User(username,password),balance(DEFAULT_BALANCE),score(0){ }

Player::Player(const string& username, const string& password, double balance, unsigned score) :
	User(username, password),score(score)
{
	if (balance < 0.0)
	{
		throw NegativeBalanceException();
	}
	this->balance = balance;
}

double Player::checkBalance()const
{
	return balance;
}

unsigned Player::checkScore()const
{
	return score;
}

void Player::profileInfo()const
{
	println("ID: {}",getId());
	println("Username: {}", getUsername());
	println("Type: Player");
	println("Balance: {}", balance);
	println("Score: {}", score);
}

UserType Player::getType()const
{
	return UserType::Player;
}

void Player::checkBarn()const
{
	barn.print();
}

void Player::checkFarm()const
{
	println("Farmland capacity: {}, Cropland capacity: {}",
		farm.getFarmlandCapacity(), farm.getCroplandCapacity());

	println("Farmland free slots: {}, Cropland free slots: {}",
		farm.getFarmlandFreeSlots(), farm.getCroplandFreeSlots());
}

void Player::expandCropland()
{
	farm.expandCropland(score);
}

void Player::expandFarmland()
{
	farm.expandFarmland(balance, score);
}

void Player::sowPlant(unsigned seedId)
{
	farm.sowPlant(seedId, barn);
}

void Player::addAnimal(unsigned animalId)
{
	farm.addAnimal(animalId,barn);
}

void Player::harvest()
{
	farm.harvest(barn);
}

void Player::buyItem(unsigned productId, unsigned quantity, Market& market)
{
	market.buy(Utils::convertIdToProduct(productId), quantity, balance, barn);
}

void Player::sellItem(unsigned productId, unsigned quantity, Market& market)
{
	market.sell(Utils::convertIdToProduct(productId), quantity, balance, barn);
}

void Player::showTaskBoard(const TaskBoard& taskBoard) const
{
	taskBoard.showTasks();
}

void Player::completeTask(unsigned taskId, TaskBoard& taskBoard)
{
	taskBoard.completeTask(taskId, barn, balance, score);
}

void Player::advanceCycles()
{
	++cycles;
	farm.tick();
}

void Player::openMarketCatalog(const Market& market)
{
	market.openMarketCatalog();
}

unsigned Player::getCycles()const
{
	return cycles;
}

Barn& Player::getBarn()
{
	return barn;
}

Farm& Player::getFarm()
{
	return farm;
}

void Player::setCycles(unsigned cycles)
{
	this->cycles = cycles;
}
