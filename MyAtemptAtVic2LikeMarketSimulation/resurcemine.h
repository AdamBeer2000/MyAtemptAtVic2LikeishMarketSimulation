#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H
#include "IProductType.h"
#include "ISource.h"
#include "singletonworldmarket.h"
#include "IProductType.h"
#include "IBudget.h"

class ResourceGatheringOperation :public ISource, public IBudget
{

private:

protected:

public:
	ResourceGatheringOperation(ProductType sourceType, double capacity, double startCash = 1000);
	void Payout()override;
	void Print()const;

	// Inherited via ISource
	virtual double GetThroughput() override;
	virtual double GetOutputEfficiency() override;

	// Inherited via ISource
	virtual double GetBaseProduction() override;
};

#endif // SOURCE_H
