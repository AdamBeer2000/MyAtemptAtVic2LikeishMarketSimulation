#include "need.h"
#include <iostream>

void Need::incraseStored(double amount)
{
	if (amountStored + amount > storageCapacity)
		throw "Sotorage would exceed capacity!";

	amountStored += amount;
}
void Need::decraseStored(double amount)
{
	if (amountStored - amount < 0)
		throw "Sotorage coudnt be negative";
	amountStored -= amount;
}

double Need::need2FillToCapacity() const
{
	return storageCapacity - amountStored;
}

double Need::getAmmountNeeded() const
{
	return ammountNeeded;
}

double Need::getAmountStored() const
{
	return amountStored;
}

void Need::Consume(double ammount)
{
	this->amountStored -= ammountNeeded * ammount;
}

double Need::ammountCanBeMade() const
{
	return amountStored / ammountNeeded;
}

double Need::getCapacity() const
{
	return storageCapacity;
}

void Need::Print() const
{
	std::cout << "[Type" << myProductType << " Stored:" << amountStored << "],";
}
