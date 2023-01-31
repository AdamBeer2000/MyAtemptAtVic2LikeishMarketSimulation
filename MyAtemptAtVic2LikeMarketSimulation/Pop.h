#pragma once

#include "IBudget.h"
#include "ISimpleConsumer.h"
#include "PopType.h"
#include "singletonworldmarket.h"

class Pop :
	public IPopType,
	public IBudget
{
protected:

	double fullfillment = 0.0;
	class PopNeed
	{
	public:
		ProductType what;
		double amount;
		PopNeed(ProductType what, double amount) :what(what), amount(amount) {};
	};
private:

	double CalcNeedFulfillment(PopNeed need);

protected:
	std::vector<std::shared_ptr<PopNeed>> needs;

public:
	Pop(PopType myType, double startCashe);
	void CalcNeedFulfillment();
	void Print()const;
	void AddNeed(PopNeed p);
	~Pop()
	{
		std::cout << "Pop delete" << std::endl;
	}
};

