#include "resurcemine.h"

void ResourceGatheringOperation::Produce(double ammount)
{
	auto market = SingletonWorldMarket::getInstance();
	ProductStorage p = ProductStorage(myProductType, ammount, this);
	market->AddToMarket(p);
}

ResourceGatheringOperation::ResourceGatheringOperation(ProductType sourceType, double capacity, double startCash) :
	ISource(capacity, startCash), IProductType(sourceType), IBudget(startCash)
{

}

void ResourceGatheringOperation::Payout()
{
	const int ownersTMP = 10;
	double income4owners = IBudget::income * 2 * ownersTMP / workers.size();
	if (income4owners > 0.5)
		income4owners = 0.5;
	double income2share = (1 - income4owners) * IBudget::income;
	double salary = income2share / workers.size();

	for (auto p : workers)
	{
		p.get()->Income(salary);
	}

	IBudget::Expense(income2share);
	IBudget::income = 0;
}

void ResourceGatheringOperation::Produce()
{
	Produce(baseCapacity);
}

void ResourceGatheringOperation::Print()const
{
	std::cout << "RGO Type: " << myProductType << " Money:" << IBudget::myBudget << std::endl;
	std::cout << "Workers : " << std::endl;
	for (auto w : workers)
	{
		w.get()->Print();
	}
	std::cout << std::endl;
}