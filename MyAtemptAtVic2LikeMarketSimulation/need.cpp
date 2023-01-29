#include "need.h"

void Need::incraseStored(double amount)
{
    if (amountStored + amount > capacity)
        throw "Sotorage would exceed capacity!";

    ammountNeeded += amount;
}
void Need::decraseStored(double amount)
{
    if (amountStored - amount < capacity)
        throw "Sotorage coudnt be negative";
    ammountNeeded -= amount;
}
void Need::store(double ammount)
{
    amountStored += ammount;
}

double Need::need2FillToCapacity() const
{
    return capacity - amountStored;
}

double Need::getAmmountNeeded() const
{
    return ammountNeeded;
}

double Need::getAmountStored() const
{
    return amountStored;
}

void Need::use(double ammount)
{
    this->amountStored -= ammountNeeded * ammount;
}

double Need::ammountCanBeMade() const
{
    return amountStored / ammountNeeded;
}

double Need::getCapacity() const
{
    return capacity;
}
