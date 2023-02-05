#include "Pop.h"
#include "Converters.h"

int Pop::allpopcount = 0;

Pop::Pop(PopType myType, double startCash, unsigned int PopSize)
	:IPopType(myType),
	PopSize(PopSize),
	IBudget(startCash)
{
	allpopcount++;
	popstackid = allpopcount;
	basicneeds = std::vector<std::shared_ptr<PopNeed>>();
}

double Pop::CalcNeedFulfillment(PopNeed need, const double moneyCap)
{
	auto marketinstance = SingletonWorldMarket::getInstance();
	double cost = marketinstance->GetCostOf(need.what);
	if (cost == DBL_MAX)return 0;
	double canBuy = moneyCap / cost;
	double needAmmount = GetNeedAmmount(need);

	if (canBuy > needAmmount)
		canBuy = needAmmount;

	bool succses = marketinstance->BuyAmount(need.what, canBuy, nullptr, this);
	if (!succses)return 0.0;
	return canBuy / needAmmount;
}

double Pop::CalcNeedFulfillment(const std::vector<std::shared_ptr<PopNeed>>& needvector)
{
	double sumFullf = 0.0;
	auto buyable = std::vector<std::shared_ptr<PopNeed>>();
	for (auto& p : needvector)
	{
		if (SingletonWorldMarket::getInstance()->IsGoodAvailable(p.get()->what))
		{
			buyable.push_back(p);
		}
	}

	const double moneyCap = IBudget::myBudget / needvector.size();

	for (auto& p : buyable)
	{
		sumFullf += CalcNeedFulfillment(*p.get(), moneyCap);
	}
	return sumFullf / needvector.size();
}

void Pop::CalcNeedFulfillment()
{
	basicNeedFullfilment = CalcNeedFulfillment(basicneeds);
	evrydayNeedFullfilment = CalcNeedFulfillment(evrydayneeds);
	luxuryNeedFullfilment = CalcNeedFulfillment(luxuryneeds);
}

void Pop::Print() const
{
	std::cout << "Pop: Type:" << PopType2String(myPopType) << " " << popstackid << std::endl;
	std::cout << " Size: " << PopSize << " Money Left: " << myBudget << std::endl;

	if (!unemployed)
		std::cout << "Insrustry : " << ProductType2String(indrustry) << std::endl;
	else
		std::cout << "Unenployed" << std::endl;

	std::cout << "Fullfilments:"
		" B:" << basicNeedFullfilment * 100 << "%; "
		" E:" << evrydayNeedFullfilment * 100 << "%; "
		" L:" << luxuryNeedFullfilment * 100 << "%; "
		<< std::endl;
	std::cout << "____________________________________________________________" << std::endl;
}

void Pop::AddNeed(PopNeed p)
{

	switch (p.importance)
	{
	case PopNeed::Importance::basic:basicneeds.push_back(std::make_shared<PopNeed>(p));
		break;
	case PopNeed::Importance::evryday: evrydayneeds.push_back(std::make_shared<PopNeed>(p));
		break;
	case PopNeed::Importance::luxury: luxuryneeds.push_back(std::make_shared<PopNeed>(p));
		break;
	}
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
	const double split = myBudget / PopSize;

	Pop* fragment = new Pop(myPopType, goes * split, goes);
	this->PopSize -= goes;
	this->myBudget = PopSize * split;
	fragment->basicneeds = this->basicneeds;
	fragment->evrydayneeds = this->evrydayneeds;
	fragment->luxuryneeds = this->luxuryneeds;

	return std::make_shared<Pop>(*fragment);
}

unsigned int Pop::GetPopSize() const
{
	return PopSize;
}

Pop::~Pop()
{
	basicneeds.clear();
	evrydayneeds.clear();
	luxuryneeds.clear();

	std::cout << "DELETED : Pop: Type:" << PopType2String(myPopType) << " " << popstackid;
	if (!unemployed)
		std::cout << " Insrustry : " << ProductType2String(indrustry) << std::endl;
	else
		std::cout << " Unenployed" << std::endl;
}
