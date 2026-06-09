#pragma once
#include"Animal.h"
#include"Crop.h"
#include"Barn.h"
#include<vector>

class Farm
{
private:
    static constexpr size_t DEFAULT_CROPLAND_CAPACITY = 3;
    static constexpr size_t DEFAULT_FARMLAND_CAPACITY = 3;

    vector<unique_ptr<Crop>> cropland;
    vector<unique_ptr<Animal>> farmland;

    size_t croplandCapacity;
    size_t farmlandCapacity;

public:
    Farm();

    size_t getCroplandCapacity()const;
    size_t getFarmlandCapacity()const;
    size_t getCroplandUsed()const;
    size_t getFarmlandUsed()const;
    size_t getFarmlandFreeSlots()const;
    size_t getCroplandFreeSlots()const;

    unique_ptr<Crop> createCrop(unsigned seedId);
    unique_ptr<Animal> createAnimal(unsigned animalId);

    void expandCropland(unsigned& score);
    void expandFarmland(double& balance, unsigned& score);
    void sowPlant(unsigned seedId, Barn& barn);
    void addAnimal(unsigned animalId,Barn& barn);
    void harvest(Barn& barn);

    void tick();
    void setCapacities(size_t cropCap, size_t farmCap);

    const vector<unique_ptr<Crop>>& getCropland() const;
    const vector<unique_ptr<Animal>>& getFarmland() const;

    void addCropFromSave(ProductType type, unsigned currentCycles);
    void addAnimalFromSave(ProductType type, unsigned currentCycles);
};

