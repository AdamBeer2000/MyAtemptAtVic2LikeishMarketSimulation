#pragma once
#include "IProductType.h"
#include "Pop.h"
#include "ISource.h"
#include "ProductCreator.h"


class Artisan :public Pop, public ISource
{
	ProductCreator* creator;
public:
	Artisan(ProductType productType, double baseOutput, unsigned int PopSize) :
		Pop(artisan, 0.0005 * PopSize, PopSize),
		ISource(productType, artisan, baseOutput, PopSize),
		IBudget(0.005 * PopSize)
	{
		this->creator = ProductCreator::GetCreatorForArtisan(productType);

		AddNeed(PopNeed(grain, 2.5));
		AddNeed(PopNeed(fish, 1));
		AddNeed(PopNeed(fruit, 1));
		AddNeed(PopNeed(wool, 1));
		AddNeed(PopNeed(cattle, 0.75));

		AddNeed(PopNeed(liquor, 5, PopNeed::evryday));
		AddNeed(PopNeed(paper, 5, PopNeed::evryday));
		AddNeed(PopNeed(regular_clothes, 5, PopNeed::evryday));
		AddNeed(PopNeed(tea, 5, PopNeed::evryday));
		AddNeed(PopNeed(furniture, 4, PopNeed::evryday));
		AddNeed(PopNeed(tobaco, 3, PopNeed::evryday));
		AddNeed(PopNeed(coal, 1, PopNeed::evryday));
		AddNeed(PopNeed(glass, 1, PopNeed::evryday));

		AddNeed(PopNeed(wine, 10, PopNeed::luxury));
		AddNeed(PopNeed(coffee, 2, PopNeed::luxury));
		AddNeed(PopNeed(telephone, 1.25, PopNeed::luxury));
		AddNeed(PopNeed(automobile, 1, PopNeed::luxury));
		AddNeed(PopNeed(luxury_clothes, 1, PopNeed::luxury));
		AddNeed(PopNeed(luxury_furniture, 1, PopNeed::luxury));
		AddNeed(PopNeed(opium, 1, PopNeed::luxury));
		AddNeed(PopNeed(radio, 1, PopNeed::luxury));
		AddNeed(PopNeed(aeroplane, 0.4, PopNeed::luxury));
		AddNeed(PopNeed(fuel, 0.2, PopNeed::luxury));

		indrustry = productType;

		unemployed = false;
	};

	virtual void Produce() override
	{
		const double BaseProduction = GetBaseProduction();
		const double Production = BaseProduction * (PopSize / 10000.0) * Economicpolicymodifiers;
		if (Production <= 0)return;

		creator->Produce(this, Production);
	}

	void Income(double a)override
	{
		IBudget::Income(a);
	}

	virtual double GetThroughput()const  override;
	virtual double GetOutputEfficiency()const override;
	virtual double GetBaseProduction()const override;
	virtual unsigned int JobOffers();
	virtual void AddWorker(std::shared_ptr<Pop> worker) override;
	virtual void Payout() override;

	// Inherited via ISource
	virtual unsigned int JobOffers() const override;
};
