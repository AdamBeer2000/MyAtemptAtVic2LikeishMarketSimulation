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
#include <vector>
#include "Converters.h"

class Market
{
private:
	class CatalogRecord :public IProductType
	{
		double baseprice;
		double currentPrice;
		std::list<std::shared_ptr<ProductStorage>> offers;
	public:

		CatalogRecord(ProductType type, const double price) :baseprice(price), currentPrice(baseprice), IProductType(type)
		{
			offers = std::list<std::shared_ptr<ProductStorage>>();
		}

		void ReCalcPrice()
		{
			double sumOffers = GetSum();

			if (sumOffers > 0 && currentPrice > GetMinPrice())
			{
				currentPrice -= 0.01;
			}
			if (sumOffers == 0 && currentPrice < GetMaxPrice())
			{
				currentPrice += 0.01;
			}
		}

		void AddOffer(ProductStorage product)
		{

			for (auto& offer : offers)
			{
				if (offer.get()->getSource() == product.getSource())
				{
					product.MergerInto(*offer.get());
					return;
				}
			}

			offers.push_back(std::make_shared<ProductStorage>(product));
		}

		double GetSum()const
		{
			double sumOffers = std::accumulate(offers.begin(), offers.end(), 0.0,
				[](double accoumulator, std::shared_ptr<ProductStorage> storage)
				{
					return accoumulator += storage.get()->getAmount();
				});
			return sumOffers;
		}

		void BuyAmmount(double& ammount)
		{
			bool canBuyThisAmmount = ammount <= GetSum();


		}

		const std::list<std::shared_ptr<ProductStorage>> GetOffers() const
		{
			return offers;
		}

		double GetMinPrice()const
		{
			return baseprice * 0.22;
		}

		double GetMaxPrice()const
		{
			return baseprice * 5;
		}

		double GetPrice()const
		{
			return currentPrice;
		}
	};
	std::map<ProductType, std::shared_ptr<CatalogRecord>> catalog;

	class Hist
	{
	public:
		std::vector<std::pair<ProductType, double>> history = std::vector<std::pair<ProductType, double>>();
		void Write2(std::ostream& stream)const
		{
			for (int i = 0; i < history.size(); i++)
			{
				stream << history[i].second << ",";
			}
		}
	};

	std::vector<Hist*> hist = std::vector<Hist*>();
public:
	Market();
	void AddToMarket(ProductStorage product);
	bool BuyAmount(ProductType ptype, double& amount, std::shared_ptr<Need> storeIn, IBudget* buyer);
	double GetCostOf(ProductType ptype)const;
	void RecalcPrices();
	bool IsGoodAvailable(ProductType ptype)const;
	bool IsGoodAvailable(ProductType ptype, const double quantitiy)const;
	void WriteHist()const;
	void Print()const;
};

#endif // MARKET_H
