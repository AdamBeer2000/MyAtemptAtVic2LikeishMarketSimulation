#include "Pop.h"

Pop::Pop(PopType myType, double startCash)
	:IPopType(myType), IBudget(startCash), ISimpleConsumer()
{

}

Pop::Pop(PopType myType, double startCash, std::map<ProductType, std::shared_ptr<Need>> needs)
	:IPopType(myType), IBudget(startCash), ISimpleConsumer(needs)
{

}

void Pop::Restock(ProductType type, double ammount)
{
	auto needptr = needs.at(type);
	auto need = needptr.get();
	auto marketinstance = SingletonWorldMarket::getInstance();
	double cost = marketinstance->GetCostOf(type);
	double canBuy = myBudget / cost;

	if (canBuy > need->getCapacity())
		canBuy = need->getCapacity();

	marketinstance->BuyAmount(type, canBuy, needptr, this);
}

void Pop::Print() const
{
	std::cout << "Pop: Type: " << myPopType << " Money:" << myBudget << " Needs : ";
	for (auto n : needs)
	{
		n.second.get()->Print();
	}
	std::cout << std::endl;
}
