#include "Pop.h"

Pop::Pop(PopType myType, double startCash)
	:IPopType(myType),
	IBudget(startCash)
{
	needs = std::vector<std::shared_ptr<PopNeed>>();
}

double Pop::CalcNeedFulfillment(PopNeed need)
{
	auto marketinstance = SingletonWorldMarket::getInstance();
	double cost = marketinstance->GetCostOf(need.what);
	if (cost == DBL_MAX)return 0;
	double canBuy = myBudget / cost;

	if (canBuy > need.amount)
		canBuy = need.amount;

	marketinstance->BuyAmount(need.what, canBuy, nullptr, this);

	return canBuy / need.amount;
}

void Pop::CalcNeedFulfillment()
{
	double sumFullf = 0.0;
	for (auto p : needs)
	{
		sumFullf += CalcNeedFulfillment(*p.get());
	}
	fullfillment = sumFullf / needs.size();
}

void Pop::Print() const
{
	std::cout << "Pop: Type: " << myPopType << " Money:" << myBudget << " Needs :[ ";
	for (auto n : needs)
	{
		std::cout << "Type: " << n.get()->what << " ,";
	}
	std::cout << "] " << "Fullfilment:" << fullfillment << "; " << std::endl;
}

void Pop::AddNeed(PopNeed p)
{
	needs.push_back(std::make_shared<PopNeed>(p));
}
