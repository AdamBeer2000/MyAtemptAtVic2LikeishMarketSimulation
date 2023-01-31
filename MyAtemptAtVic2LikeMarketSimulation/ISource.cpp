#include "ISource.h"

void ISource::AddWorker(std::shared_ptr<Pop> worker)
{
	if (workforceCapacity == workers.size())
		throw "workforceCapacity exceeded";

	workers.push_back(worker);
}

void ISource::AddOwner(std::shared_ptr<Pop> owner)
{
	owners.push_back(owner);
}

void ISource::Produce()
{
	auto market = SingletonWorldMarket::getInstance();
	double Production = GetBaseProduction() * GetThroughput() * GetOutputEfficiency();
	ProductStorage p = ProductStorage(myProductType, Production, this);
	market->AddToMarket(p);
}
