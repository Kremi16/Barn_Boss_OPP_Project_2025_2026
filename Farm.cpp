#include "Farm.h"
#include"Wheat.h"
#include"Corn.h"
#include"Chicken.h"
#include"Cow.h"
#include"InsufficientScoreException.h"
#include"InsufficientBalanceException.h"
#include"CroplandFullException.h"
#include"FarmlandFullException.h"
#include"ItemNotFoundException.h"
#include"InvalidAnimalInputException.h"
#include"InvalidCropInputException.h"
#include<iostream>

Farm::Farm():croplandCapacity(DEFAULT_CROPLAND_CAPACITY),farmlandCapacity(DEFAULT_FARMLAND_CAPACITY){}

size_t Farm::getCroplandCapacity()const
{
	return croplandCapacity;
}

size_t Farm::getFarmlandCapacity()const
{
	return farmlandCapacity;
}

size_t Farm::getCroplandUsed()const
{
	return cropland.size();
}

size_t Farm::getFarmlandUsed()const
{
	return farmland.size();
}

size_t Farm::getCroplandFreeSlots()const
{
	return croplandCapacity - getCroplandUsed();
}

size_t Farm::getFarmlandFreeSlots()const
{
	return farmlandCapacity - getFarmlandUsed();
}

void Farm::expandCropland(unsigned& score)
{
	if (score < croplandCapacity * 10)
	{
		throw InsufficientScoreException(croplandCapacity * 10, score);
	}

	score -= croplandCapacity * 10;
	croplandCapacity++;
}

void Farm::expandFarmland(double& balance, unsigned& score)
{
	unsigned cost = 50 * farmlandCapacity;
	unsigned requiredScore = farmlandCapacity * 10;

	if (score < requiredScore)
	{
		throw InsufficientScoreException(requiredScore, score);
	}

	if (balance < cost)
	{
		throw InsufficientBalanceException(cost, balance);
	}

	score -= requiredScore;
	balance -= cost;
	farmlandCapacity++;
}

void Farm::sowPlant(unsigned seedId, Barn& barn)
{
	if (cropland.size() >= croplandCapacity)
	{
		throw CroplandFullException();
	}

	ProductType seed = Utils::convertIdToProduct(seedId);

	if (!barn.hasItem(seed, 1))
	{
		throw ItemNotFoundException(seed);
	}
	barn.remove(seed, 1);

	auto crop = createCrop(seedId);
	cropland.push_back(move(crop));
	cout << "Plants planted successfully!" << '\n';
}

void Farm::addAnimal(unsigned animalId,Barn& barn)
{
	if (farmland.size() >= farmlandCapacity)
	{
		throw FarmlandFullException();
	}

	ProductType type = Utils::convertIdToProduct(animalId);
	if (!barn.hasItem(type, 1))
	{
		throw ItemNotFoundException(type);
	}

	barn.remove(type, 1);
	farmland.push_back(createAnimal(animalId));
	cout << "Animals added successfully!" << '\n';
}

unique_ptr<Crop> Farm::createCrop(unsigned seedId)
{
	switch (seedId)
	{
	case 1: return make_unique<Wheat>();
	case 2: return make_unique<Corn>();

	default:
		throw InvalidCropInputException();
	}
}

unique_ptr<Animal> Farm::createAnimal(unsigned animalId)
{
	switch (animalId)
	{
	case 3: return make_unique<Chicken>();
	case 4: return make_unique<Cow>();

	default:
		throw InvalidAnimalInputException();
	}
}

void Farm::harvest(Barn& barn)
{
	for (auto it = cropland.begin(); it != cropland.end(); )
	{
		if ((*it)->isReady())
		{
			barn.add((*it)->getProduct(), 1);
			it = cropland.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = farmland.begin(); it != farmland.end(); )
	{
		if ((*it)->isReady())
		{
			barn.add((*it)->getProduct(), 1);
			it = farmland.erase(it);
		}
		else
		{
			++it;
		}
	}
	cout << "Harvest completed!" << '\n';
}

void Farm::tick()
{
	for (auto& crop : cropland)
	{
		crop->tick();
	}

	for (auto& animal : farmland)
	{
		animal->tick();
	}
}

const vector<unique_ptr<Crop>>& Farm::getCropland() const
{
	return cropland;
}

const vector<unique_ptr<Animal>>& Farm::getFarmland() const
{
	return farmland;
}

void Farm::setCapacities(size_t cropCap, size_t farmCap)
{
	croplandCapacity = cropCap;
	farmlandCapacity = farmCap;
}

void Farm::addCropFromSave(ProductType type, unsigned currentCycles)
{
	unique_ptr<Crop> crop;
	switch (type)
	{
	case ProductType::Wheat:
	{
		crop = make_unique<Wheat>(); 
		break;
	}
	case ProductType::Corn:
	{
		crop = make_unique<Corn>();  
		break;
	}
	default: throw InvalidCropInputException();
	}

	for (unsigned i = 0; i < currentCycles; i++)
	{
		crop->tick();
	}
	cropland.push_back(move(crop));
}

void Farm::addAnimalFromSave(ProductType type, unsigned currentCycles)
{
	unique_ptr<Animal> animal;
	switch (type)
	{
	case ProductType::Chicken:
	{
		animal = make_unique<Chicken>(); 
		break;
	}
	case ProductType::Cow:
	{
		animal = make_unique<Cow>();
		break;
	}
	default: throw InvalidAnimalInputException();
	}

	for (unsigned i = 0; i < currentCycles; i++)
	{
		animal->tick();
	}
	farmland.push_back(move(animal));
}