#include "market.h"
#include "IBudget.h"

Market::Market()
{
	catalog = std::map<ProductType, std::shared_ptr<CatalogRecord>>();

	catalog.insert({ ProductType::beer,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::beer,200.0)) });
	catalog.insert({ ProductType::greap,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::greap,200.0)) });
	catalog.insert({ ProductType::wheat,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::wheat,200.0)) });
	catalog.insert({ ProductType::wine,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::wine,200.0)) });
}

void Market::AddToMarket(ProductStorage product)
{
	auto record = catalog.at(product.getType());
	record->offers.push_back(std::make_shared<ProductStorage>(product));
}

void Market::BuyAmount(ProductType ptype, unsigned int amount, std::shared_ptr<Need> storeIn, IBudget* buyer)
{
	auto rec = catalog.at(ptype);
	auto offers = rec.get()->offers;
	auto SuitableOffers = std::find_if(offers.begin(), offers.end(), [&amount](std::shared_ptr<ProductStorage> p)
		{
			return p.get()->getAmount() >= amount;
		});
	if (SuitableOffers == std::end(offers))return;

	std::shared_ptr<ProductStorage> p = *SuitableOffers;
	auto source = p.get()->getSource();
	source->Income(rec.get()->price * amount);
	buyer->Expense(rec.get()->price * amount);
	p.get()->decreaseBy(amount);
	storeIn.get()->store(amount);
}

double Market::GetCostOf(ProductType ptype)const
{
	if (catalog.find(ptype) != catalog.end())
		return catalog.at(ptype).get()->price;
	return DBL_MAX;
}

void Market::Print() const
{
	for (auto kvp : catalog)
	{
		std::cout << kvp.first << ":" << std::endl;
		for (auto offer : kvp.second->offers)
		{
			std::cout << offer.get()->getAmount() << std::endl;
		}
	}
}

