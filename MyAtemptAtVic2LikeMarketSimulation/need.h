#ifndef Need_H
#define Need_H

#include "IProductType.h"

class Need :public IProductType
{
	double ammountNeeded;
	double amountStored;
	double storageCapacity;



public:
	Need(ProductType type, double ammountNeeded, double amountStored = 100, double storageCapacity = 100)
		:IProductType(type), ammountNeeded(ammountNeeded), amountStored(amountStored), storageCapacity(storageCapacity)
	{

	}
	double need2FillToCapacity()const;
	double getAmmountNeeded() const;
	double getAmountStored() const;
	void Consume(double ammount);
	double ammountCanBeMade() const;
	double getCapacity()const;

	void incraseStored(double amount);
	void decraseStored(double amount);

	void Print()const;

};

#endif // DEBUG