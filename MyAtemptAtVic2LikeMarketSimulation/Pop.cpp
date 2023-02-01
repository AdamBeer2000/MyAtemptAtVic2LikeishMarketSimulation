#include "Pop.h"

Pop::Pop(PopType myType, double startCash, unsigned int PopSize)
	:IPopType(myType),
	PopSize(PopSize),
	IBudget(startCash)
{
	basicneeds = std::vector<std::shared_ptr<PopNeed>>();
}

double Pop::CalcNeedFulfillment(PopNeed need)
{
	auto marketinstance = SingletonWorldMarket::getInstance();
	double cost = marketinstance->GetCostOf(need.what);
	if (cost == DBL_MAX)return 0;
	double canBuy = myBudget / cost;
	double needAmmount = GetNeedAmmount(need);
	if (canBuy > needAmmount)
		canBuy = needAmmount;

	bool succses = marketinstance->BuyAmount(need.what, canBuy, nullptr, this);
	if (!succses)return 0.0;
	return canBuy / needAmmount;
}

void Pop::CalcNeedFulfillment()
{
	double sumFullf = 0.0;
	for (auto p : basicneeds)
	{
		sumFullf += CalcNeedFulfillment(*p.get());
	}
	basicNeedFullfilment = sumFullf / basicneeds.size();
}

void Pop::Print() const
{
	std::cout << "Pop: Type:" << myPopType << "Size: " << PopSize << " Money: " << myBudget << " Fullfilment:" << basicNeedFullfilment << "; " << std::endl;
}

void Pop::AddNeed(PopNeed p)
{
	basicneeds.push_back(std::make_shared<PopNeed>(p));
}

double Pop::GetNeedAmmount(PopNeed need)
{
	double tmp = (1 + Plurality) * (1 + 2 * CON / PDEF_BASE_CON) * (1 + inventions * INVENTION_IMPACT_ON_DEMAND) * (need.amount) * BASE_GOODS_DEMAND * PopSize / 200000;
	return tmp;
}

bool Pop::IsUnemployed() const
{
	return unemployed;
}

std::shared_ptr<Pop> Pop::fragment(unsigned int goes)
{
	Pop fragment = Pop(*this);
	fragment.PopSize = goes;
	this->PopSize = PopSize - goes;

	return std::make_shared<Pop>(fragment);
}
