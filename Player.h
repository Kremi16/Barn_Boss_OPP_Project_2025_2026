#pragma once
#include"User.h"
#include"Farm.h"
#include"Barn.h"
#include"Market.h"
#include"TaskBoard.h"

class Player:public User
{
private:
	static constexpr double DEFAULT_BALANCE = 100.0;
	Barn barn;
	Farm farm;
	double balance;
	unsigned score;
	unsigned cycles = 0;

public:
	Player() = default;
	Player(const string& username, const string& password);
	Player(const string& username, const string& password, double balance, unsigned score);

	void profileInfo()const override;
	UserType getType()const override;

	unsigned getCycles()const;
	Barn& getBarn();
	Farm& getFarm();

	double checkBalance()const;
	unsigned checkScore()const;
	void checkBarn()const;
	void checkFarm()const;

	void expandCropland();
	void expandFarmland();

	void sowPlant(unsigned seedId);
	void addAnimal(unsigned animalId);
	void harvest();

	void buyItem(unsigned productId, unsigned quantity, Market& market);
	void sellItem(unsigned productId, unsigned quantity, Market& market);
	void showTaskBoard(const TaskBoard& taskBoard) const;
	void completeTask(unsigned taskId, TaskBoard& taskBoard);
	
	void advanceCycles();
	void openMarketCatalog(const Market& market);
	void setCycles(unsigned cycles);
};

