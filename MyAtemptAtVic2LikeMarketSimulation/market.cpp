#include "market.h"
#include "IBudget.h"

Market::Market()
{
	catalog = std::map<ProductType, std::shared_ptr<CatalogRecord>>();

	catalog.insert({ ProductType::beer,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::beer,50)) });
	catalog.insert({ ProductType::grain,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::grain,2.2)) });
}

void Market::AddToMarket(ProductStorage product)
{
	auto record = catalog.at(product.getType());
	record->offers.push_back(std::make_shared<ProductStorage>(product));
}

bool Market::BuyAmount(ProductType ptype, double& amount, std::shared_ptr<Need> storeIn, IBudget* buyer)
{
	if (catalog.find(ptype) == catalog.end())return false;
	if (amount == 0)return false;
	auto rec = catalog.at(ptype);

	auto offers = rec.get()->offers;

	auto BestFitOffer = std::min_element(offers.begin(), offers.end(), [&amount](std::shared_ptr<ProductStorage> a, std::shared_ptr<ProductStorage> b)->bool
		{
			return abs(a.get()->getAmount() - amount) < abs(b.get()->getAmount() - amount);
		});

	if (BestFitOffer == std::end(offers))return false;

	std::shared_ptr<ProductStorage> p = *BestFitOffer;
	auto source = p.get()->getSource();
	if (p.get()->getAmount() < amount)
		amount = p.get()->getAmount();

	double cost = rec.get()->price * amount;
	source->Income(cost);
	buyer->Expense(cost);
	p.get()->decreaseBy(amount);
	if (storeIn)
		storeIn.get()->incraseStored(amount);
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

