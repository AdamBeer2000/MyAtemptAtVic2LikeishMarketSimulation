#pragma once
#include "IProductType.h"
#include "Pop.h"
#include "ISource.h"

class ProductCreator
{
	struct ProduceNeed
	{
		ProductType neededProduct;
		double neededAmmount;
		double storedAmmount;
	};
};
class Artisan :public Pop, public ISource
{
public:
	Artisan(ProductType productType, double baseOutput, unsigned int PopSize) :
		Pop(artisan, 0.01, PopSize),
		ISource(productType, artisan, baseOutput, PopSize)
	{

	}
	virtual void Produce()override
	{
		const double BaseProduction = GetBaseProduction();
		const double Throughput = GetThroughput();
		const double OutputEfficiency = GetOutputEfficiency();
		const double Production = BaseProduction * Throughput * OutputEfficiency;
		if (Production <= 0)return;

		ProductStorage p = ProductStorage(myProductType, Production, nullptr);

		SingletonWorldMarket::getInstance()->AddToMarket(p);
	}
	virtual double GetThroughput() override;
	virtual double GetOutputEfficiency() override;
	virtual double GetBaseProduction()override;
	virtual unsigned int JobOffers();
	virtual void AddWorker(std::shared_ptr<Pop> worker) override;
	virtual void Payout() override;
};
