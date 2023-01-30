#pragma once

#include "IBudget.h"
#include "ISimpleConsumer.h"
#include "PopType.h"
#include "singletonworldmarket.h"

class Pop :
	public IPopType,
	public IBudget,
	public ISimpleConsumer
{
public:
	Pop(PopType myType, double startCashe);
	Pop(PopType myType, double startCash, std::map<ProductType, std::shared_ptr<Need>> needs);
	void Restock(ProductType type, double ammount) override;
	void Restock()override
	{
		ISimpleConsumer::Restock();
	};
	void Print()const;
};

