#pragma once
#include"Utils.h"
#include<string>
#include<memory>
using namespace std;

class FarmObject
{
private:
	unsigned currentCycles;
	unsigned requiredCycles;

public:
	FarmObject();
	explicit FarmObject(unsigned requiredCycles);

	virtual ProductType getProduct()const = 0;
	virtual ~FarmObject() = default;

	void tick();
	bool isReady()const;
	unsigned getCurrentCycles()const;
	unsigned getRequiredCycles()const;
};

