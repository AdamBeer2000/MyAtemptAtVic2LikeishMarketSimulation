#include "resurcemine.h"

void ResourceMine::Produce(double ammount)
{
	auto market = SingletonWorldMarket::getInstance();
	ProductStorage p = ProductStorage(myProductType, ammount, this);
	market->AddToMarket(p);
}

ResourceMine::ResourceMine(ProductType sourceType, double capacity, double startCash) : ISource(capacity), IProductType(sourceType), IBudget(startCash)
{

}

void ResourceMine::Produce()
{
	Produce(myCapacity);
}
