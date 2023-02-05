#pragma once

#include "IBudget.h"
#include "ISimpleConsumer.h"
#include "PopType.h"
#include "singletonworldmarket.h"
#include "PlaceholderDEFINES.h"

class Pop :
	public IPopType,
	virtual public IBudget
{
protected:

	double basicNeedFullfilment = 0.0;
	double evrydayNeedFullfilment = 0.0;
	double luxuryNeedFullfilment = 0.0;

	static int allpopcount;
	int popstackid = 0;

	unsigned int PopSize = 1;
	bool unemployed = true;
	ProductType indrustry;

	class PopNeed
	{
	public:
		enum Importance
		{
			basic, evryday, luxury
		};

		Importance importance;

		ProductType what;
		double amount;

		PopNeed(ProductType what, double amount, Importance importance = basic) :what(what), amount(amount), importance(importance) {};
	};
private:

	double CalcNeedFulfillment(PopNeed need, const double cap);
	double CalcNeedFulfillment(const std::vector<std::shared_ptr<PopNeed>>& needvector);

protected:
	std::vector<std::shared_ptr<PopNeed>> basicneeds = std::vector<std::shared_ptr<PopNeed>>();
	std::vector<std::shared_ptr<PopNeed>> evrydayneeds = std::vector<std::shared_ptr<PopNeed>>();
	std::vector<std::shared_ptr<PopNeed>> luxuryneeds = std::vector<std::shared_ptr<PopNeed>>();


public:
	Pop(PopType myType, double startCashe, unsigned int PopSize);

	void CalcNeedFulfillment();
	void Print()const;
	void AddNeed(PopNeed p);
	double GetNeedAmmount(PopNeed type);
	bool IsUnemployed()const;
	void SetUnemploed(bool set2, ProductType indrustry)
	{
		this->indrustry = indrustry;
		unemployed = set2;
	}
	std::shared_ptr<Pop> fragment(unsigned int goes);

	unsigned int GetPopSize()const;
	~Pop();
};

