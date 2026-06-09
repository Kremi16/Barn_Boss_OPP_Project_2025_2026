#pragma once
#include"Utils.h"
#include<vector>

class Barn
{
private:
	vector<unsigned> items;

	unsigned toIndex(ProductType type)const;

public:
	Barn();

	void add(ProductType type, unsigned quantity);
	void remove(ProductType type, unsigned quantity);
	bool hasItem(ProductType type, unsigned quantity) const;
	unsigned getItemQuantity(ProductType type) const;

	void print()const;
};

