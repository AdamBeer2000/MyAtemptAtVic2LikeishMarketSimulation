#include "ISimpleConsumer.h"

ISimpleConsumer::ISimpleConsumer()
{
	needs = std::map<ProductType, std::shared_ptr<Need>>();
}
ISimpleConsumer::ISimpleConsumer(std::map<ProductType, std::shared_ptr<Need>> needs) :needs(needs)
{

}
void ISimpleConsumer::Consume(ProductType type, double ammount)
{
	auto element = needs.find(type);
	if (element == needs.end()) throw "";
	auto need = (*element).second.get();
	auto stored = need->getAmountStored();
	if (ammount > stored)
		ammount = stored;
	need->decraseStored(ammount);
}

void ISimpleConsumer::Restock(ProductType type, double ammount)
{
	auto element = needs.find(type);
	if (needs.find(type) == needs.end()) throw "";
	(*element).second.get()->incraseStored(ammount);
}

void ISimpleConsumer::Restock()
{
	for (auto needkvp : needs)
	{
		Restock(needkvp.first, needkvp.second.get()->getCapacity());
	}
}

void ISimpleConsumer::Consume()
{
	for (auto needkvp : needs)
	{
		Consume(needkvp.first, 1);
	}
}

void ISimpleConsumer::AddNeed(Need n)
{
	needs.insert({ n.getProductType(),std::make_shared<Need>(n) });
}

std::vector<ProductType> ISimpleConsumer::GetNeedTypes()
{
	auto keys = std::vector<ProductType>();
	for (auto keyvalue : needs)
	{
		keys.push_back(keyvalue.first);
	}
	return keys;
}

