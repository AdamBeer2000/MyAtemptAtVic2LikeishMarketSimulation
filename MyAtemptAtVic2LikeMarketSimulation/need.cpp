#include "need.h"

void Need::incraseStored(double amount)
{
	if (amountStored + amount > storageCapacity)
		throw "Sotorage would exceed capacity!";

	ammountNeeded += amount;
}
void Need::decraseStored(double amount)
{
	if (amountStored - amount < storageCapacity)
		throw "Sotorage coudnt be negative";
	ammountNeeded -= amount;
}
void Need::Restock(double ammount)
{
	amountStored += ammount;
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
