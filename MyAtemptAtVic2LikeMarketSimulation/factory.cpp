#include "factory.h"

Factory::Factory(ProductType sourceType, double capacity, std::vector<std::shared_ptr<Need>>needs, double startCash)
	:ISource(capacity), IProductType(sourceType), IBudget(startCash), needs(needs)
{

}
void Factory::Produce()
{
	auto lambda = [](const std::shared_ptr<Need> a, const std::shared_ptr<Need> b)->bool
	{
		return a->ammountCanBeMade() < b->ammountCanBeMade();
	};
	std::vector<std::shared_ptr<Need>>::iterator minimumElement = std::min_element(needs.begin(), needs.end(), lambda);
	double canBeMade = ((std::shared_ptr<Need>) * minimumElement)->ammountCanBeMade();

	if (canBeMade < myCapacity)
	{
		for (auto n : needs)
		{
			n->use(canBeMade);
		}

		Factory::Produce(canBeMade);

	}
	else
	{
		for (auto n : needs)
		{
			n->use(myCapacity);
		}

		Factory::Produce(myCapacity);
	}
}

void Factory::Restock()
{
	auto instancle = SingletonWorldMarket::getInstance();

	for (auto n : needs)
	{
		double cost = instancle->GetCostOf(n.get()->getProductType());
		double need = n->need2FillToCapacity();
		double canBuy = myBudget / cost;

		if (canBuy > n->getCapacity())
			canBuy = n->getCapacity();

		instancle->BuyAmount(n.get()->getProductType(), canBuy, n, this);
	}
}

void Factory::Print()
{
	std::cout << "Type: " << myProductType << " Money:" << myBudget << " Needs : ";
	for (auto n : needs)
	{
		std::cout << "[Type" << n.get()->getProductType() << " Stored:" << n.get()->getAmountStored() << "],";
	}
	std::cout << std::endl;
}

void Factory::Produce(double ammount)
{
	auto instancle = SingletonWorldMarket::getInstance();
	instancle->AddToMarket(ProductStorage(myProductType, ammount, this));
}
