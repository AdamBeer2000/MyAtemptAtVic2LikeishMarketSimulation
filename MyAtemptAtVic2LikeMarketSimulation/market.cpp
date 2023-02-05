#include "market.h"
#include "IBudget.h"
#include <fstream>

Market::Market()
{
	catalog = std::map<ProductType, std::shared_ptr<CatalogRecord>>();

	catalog.insert({ ProductType::cattle,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::cattle,1.8)) });
	catalog.insert({ ProductType::coal,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::coal,2.4)) });
	catalog.insert({ ProductType::coffee,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::coffee,1.5)) });
	catalog.insert({ ProductType::cotton,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::cotton,2.2)) });
	catalog.insert({ ProductType::dye,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::dye,0.22)) });
	catalog.insert({ ProductType::fish,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::fish,2.2)) });
	catalog.insert({ ProductType::grain,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::grain,1.8)) });
	catalog.insert({ ProductType::iron,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::iron,1.8)) });
	catalog.insert({ ProductType::oil,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::oil,1)) });
	catalog.insert({ ProductType::opium,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::opium,0.7)) });
	catalog.insert({ ProductType::fruit,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::fruit,2.8)) });
	catalog.insert({ ProductType::precious_metal,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::precious_metal,2.0)) });
	catalog.insert({ ProductType::rubber,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::rubber,0.75)) });
	catalog.insert({ ProductType::wool,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::wool,5)) });
	catalog.insert({ ProductType::silk,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::silk,0.25)) });
	catalog.insert({ ProductType::sulphur,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::sulphur,2)) });
	catalog.insert({ ProductType::tea,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::tea,1.75)) });
	catalog.insert({ ProductType::timber,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::timber,8)) });
	catalog.insert({ ProductType::tobaco,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::tobaco,2.5)) });
	catalog.insert({ ProductType::tropical_wood,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::tropical_wood,4)) });

	catalog.insert({ ProductType::aeroplane,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::aeroplane,110)) });
	catalog.insert({ ProductType::ammunition,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::ammunition,17.5)) });
	catalog.insert({ ProductType::artillery,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::artillery,60)) });
	catalog.insert({ ProductType::automobile,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::automobile,70)) });
	catalog.insert({ ProductType::canned_food,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::canned_food,16)) });
	catalog.insert({ ProductType::cement,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::cement,16)) });
	catalog.insert({ ProductType::clipper,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::clipper,42)) });
	catalog.insert({ ProductType::fabric,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::fabric,1.8)) });
	catalog.insert({ ProductType::electric_gear,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::electric_gear,5)) });
	catalog.insert({ ProductType::explosives,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::explosives,20)) });
	catalog.insert({ ProductType::fertilizer,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::fertilizer,10)) });
	catalog.insert({ ProductType::fuel,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::fuel,25)) });
	catalog.insert({ ProductType::furniture,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::furniture,4.90)) });
	catalog.insert({ ProductType::glass,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::glass,2.9)) });
	catalog.insert({ ProductType::liquor,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::liquor,6.4)) });
	catalog.insert({ ProductType::lumber,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::lumber,1)) });
	catalog.insert({ ProductType::luxury_clothes,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::luxury_clothes,65)) });
	catalog.insert({ ProductType::luxury_furniture,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::luxury_furniture,59)) });
	catalog.insert({ ProductType::machine_parts,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::machine_parts,36)) });
	catalog.insert({ ProductType::paper,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::paper,3.4)) });
	catalog.insert({ ProductType::radio,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::radio,16)) });
	catalog.insert({ ProductType::regular_clothes,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::regular_clothes,5.8)) });
	catalog.insert({ ProductType::small_arms,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::small_arms,37)) });
	catalog.insert({ ProductType::steamer,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::steamer,65)) });
	catalog.insert({ ProductType::steel,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::steel,4.7)) });
	catalog.insert({ ProductType::tanks,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::tanks,98)) });
	catalog.insert({ ProductType::telephone,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::telephone,16)) });
	catalog.insert({ ProductType::wine,std::shared_ptr<Market::CatalogRecord>(new Market::CatalogRecord(ProductType::wine,9.7)) });
}

void Market::AddToMarket(ProductStorage product)
{
	auto record = catalog.at(product.getType());
	record.get()->AddOffer(product);
	//record->offers.push_back(std::make_shared<ProductStorage>(product));
}

bool Market::BuyAmount(ProductType ptype, double& amount, std::shared_ptr<Need> storeIn, IBudget* buyer)
{
	if (catalog.find(ptype) == catalog.end())return false;
	if (amount == 0)return false;

	auto rec = catalog.at(ptype);
	double price = rec.get()->GetPrice();

	double storedAll = rec.get()->GetSum();

	if (storedAll == 0)return false;

	if (amount > storedAll)
		amount = storedAll;

	auto offers = rec.get()->GetOffers();

	for (auto offer : offers)
	{
		const double stored = offer.get()->getAmount();
		const double ratio = stored / storedAll;
		const double buyRatio = ratio * amount;
		const double profit4source = buyRatio * price;
		offer.get()->getSource()->Income(profit4source);
	}

	buyer->Expense(amount * price);

	if (storeIn)
		storeIn.get()->incraseStored(amount);

	return true;
}

double Market::GetCostOf(ProductType ptype)const
{
	if (catalog.find(ptype) != catalog.end())
		return catalog.at(ptype).get()->GetPrice();
	return DBL_MAX;
}

void Market::RecalcPrices()
{
	auto h = new Hist();
	hist.push_back(h);
	for (auto kvp : catalog)
	{
		h->history.push_back({ kvp.first,kvp.second.get()->GetPrice() });
		kvp.second.get()->ReCalcPrice();
	}
}

bool Market::IsGoodAvailable(ProductType ptype) const
{
	return catalog.find((ptype)) != catalog.end();
}

bool Market::IsGoodAvailable(ProductType ptype, const double quantitiy) const
{
	auto cat = catalog.find((ptype));
	if (catalog.find((ptype)) == catalog.end())return false;
	else return ((std::pair<ProductType, std::shared_ptr<CatalogRecord>>) * cat).second.get()->GetSum() >= quantitiy;
}

void Market::WriteHist() const
{
	std::ofstream MyFile("save.csv");
	for (auto p : GetAllProductType())
	{
		MyFile << ProductType2String(p) << ",";
	}
	MyFile << std::endl;
	for (int i = 0; i < hist.size(); i++)
	{
		hist[i]->Write2(MyFile);
		MyFile << std::endl;
	}
	MyFile.close();
}

void Market::Print() const
{
	for (auto kvp : catalog)
	{
		std::cout << kvp.first << ":" << std::endl;
		for (auto offer : kvp.second.get()->GetOffers())
		{
			std::cout << offer.get()->getAmount() << std::endl;
		}
	}
}

