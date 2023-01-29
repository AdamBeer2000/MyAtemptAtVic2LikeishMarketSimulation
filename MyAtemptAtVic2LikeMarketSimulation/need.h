#ifndef Need_H
#define Need_H

#include "IProductType.h"

class Need :public IProductType
{
	double ammountNeeded;
	double amountStored;
	double capacity;

	void incraseStored(double amount);
	void decraseStored(double amount);

public:
	Need(ProductType type, double ammountNeeded, double amountStored = 100, double capacity = 100)
		:IProductType(type), ammountNeeded(ammountNeeded), amountStored(amountStored), capacity(capacity)
	{

	}
	void store(double ammount);
	double need2FillToCapacity()const;
	double getAmmountNeeded() const;
	double getAmountStored() const;
	void use(double ammount);
	double ammountCanBeMade() const;
	double getCapacity()const;

};

#endif // DEBUG