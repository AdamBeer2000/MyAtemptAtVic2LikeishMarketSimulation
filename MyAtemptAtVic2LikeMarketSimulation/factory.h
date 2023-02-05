#pragma once

#include "ISource.h"
#include <vector>
#include <algorithm>
#include "singletonworldmarket.h"
#include "need.h"
#include "IProductType.h"
#include "IBudget.h"
#include "ProductCreator.h"

class Factory :public ISource
{
	ProductCreator* creator;
	std::vector<std::shared_ptr<Pop>> workers;
	unsigned int clerkcount = 0;
	unsigned int craftmancount = 0;
	double baseInput;
public:
	Factory(ProductType productType, double baseOutput, double baseInput, unsigned int FactorySizeBase) :
		ISource(productType, artisan, baseOutput, FactorySizeBase),
		IBudget(100), baseInput(baseInput)
	{
		this->creator = ProductCreator::GetCreatorForFactory(productType);
	};
	virtual void Produce() override
	{

	}

	unsigned int GetWorkforceSize()const
	{
		return std::accumulate(workers.begin(), workers.end(), 0, [](int accumulator, std::shared_ptr<Pop> p) {return accumulator + p.get()->GetPopSize(); });
	}


	virtual double GetThroughput()const  override;
	virtual double GetOutputEfficiency()const override;
	virtual double GetInputEfficiency()const;
	virtual double GetBaseProduction()const override;

	virtual double GetInput(double baseinput)const;
	virtual double GetOutput()const;

	void IsBankrupt()const;
	bool CanIWorkHere(PopType p) const;

	virtual unsigned int JobOffers();
	virtual void AddWorker(std::shared_ptr<Pop> worker) override;
	virtual void Payout() override;
};