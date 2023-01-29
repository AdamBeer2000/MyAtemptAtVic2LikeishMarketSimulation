#include "ISimpleConsumer.h"

ISimpleConsumer::ISimpleConsumer()
{
	needs = std::map<ProductType, std::shared_ptr<Need>>();
}

void ISimpleConsumer::Consume(ProductType type, double ammount)
{
	auto element = needs.find(type);
	if (element == needs.end()) throw "";
	(*element).second.get()->Consume(ammount);
}

void ISimpleConsumer::Restock(ProductType type, double ammount)
{
	auto element = needs.find(type);
	if (needs.find(type) == needs.end()) throw "";
	(*element).second.get()->Restock(ammount);
}

void ISimpleConsumer::AddNeed(Need n)
{
	needs.insert({ n.getProductType(),std::make_shared<Need>(n) });
}

std::vector<ProductType> IConsumer::GetNeedTypes()
{
	auto keys = std::vector<ProductType>();
	for (auto keyvalue : needs)
	{
		keys.push_back(keyvalue.first);
	}
	return keys;
}
