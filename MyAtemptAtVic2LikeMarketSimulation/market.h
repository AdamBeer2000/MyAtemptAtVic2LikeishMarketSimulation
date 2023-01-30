#ifndef MARKET_H
#define MARKET_H
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "product.h"
#include "need.h"

class Market
{
private:
	class CatalogRecord :public IProductType
	{
	public:
		double price;
		std::list<std::shared_ptr<ProductStorage>> offers;

		CatalogRecord(ProductType type, double price) :price(price), IProductType(type)
		{
			offers = std::list<std::shared_ptr<ProductStorage>>();
		}
	};
	std::map<ProductType, std::shared_ptr<CatalogRecord>> catalog;

public:
	Market();
	void AddToMarket(ProductStorage product);
	bool BuyAmount(ProductType ptype, unsigned int amount, std::shared_ptr<Need> storeIn, IBudget* buyer);
	double GetCostOf(ProductType ptype)const;
	void Print()const;
};

#endif // MARKET_H
