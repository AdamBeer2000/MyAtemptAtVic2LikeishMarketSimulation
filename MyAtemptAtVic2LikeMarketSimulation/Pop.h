#pragma once

#include "IBudget.h"
#include "ISimpleConsumer.h"
#include "PopType.h"
#include "singletonworldmarket.h"
#include "PlaceholderDEFINES.h"

class Pop :
	public IPopType,
	public IBudget
{
protected:

	double basicNeedFullfilment = 0.0;
	double evrydayNeedFullfilment = 0.0;
	double luxuryNeedFullfilment = 0.0;

	unsigned int PopSize = 1;
	bool unemployed = true;

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
	std::vector<std::shared_ptr<PopNeed>> basicneeds;
	std::vector<std::shared_ptr<PopNeed>> evrydayneeds;
	std::vector<std::shared_ptr<PopNeed>> luxuryneeds;


public:
	Pop(PopType myType, double startCashe, unsigned int PopSize);
	void CalcNeedFulfillment();
	void Print()const;
	void AddNeed(PopNeed p);
	double GetNeedAmmount(PopNeed type);
	bool IsUnemployed()const;
	void SetUnemploed(bool set2)
	{
		unemployed = set2;
	}
	std::shared_ptr<Pop> fragment(unsigned int goes);

	unsigned int GetPopSize()const
	{
		return PopSize;
	}
	~Pop()
	{
		std::cout << "Pop delete" << std::endl;
	}
};

