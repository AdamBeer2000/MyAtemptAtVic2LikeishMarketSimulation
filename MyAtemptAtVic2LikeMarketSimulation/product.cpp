#include "product.h"


IBudget* ProductStorage::getSource() const
{
	return mySource;
}


void ProductStorage::MergerInto(ProductStorage& other)
{
	other.increaseBy(this->amount);
}

ProductStorage::ProductStorage(ProductType pType, double amount, IBudget* pSource)
	:myType(pType), amount(amount), mySource(pSource)
{

}

double ProductStorage::getAmount() const
{
	return amount;
}

void ProductStorage::increaseBy(double amount)
{
	this->amount += amount;
}

void ProductStorage::decreaseBy(double amount)
{
	if (this->amount - amount < 0)
		throw "Stored product ammount" + std::to_string(this->amount) + " decrased by too much (" + std::to_string(amount) + ")";
	this->amount -= amount;
}

ProductType ProductStorage::getType() const
{
	return myType;
}

