#ifndef SOURCE_H
#define SOURCE_H
#include "Pop.h"
#include "IBudget.h"
#include "IProductType.h"
#include "singletonworldmarket.h"

class ISource :public IBudget, public IProductType
{

private:

protected:
	double OutputAmount;
	int workforceCapacity;
	double payoutPercent;
	std::vector<std::shared_ptr<Pop>> workers;
	std::vector<std::shared_ptr<Pop>> owners;
	virtual double GetThroughput() = 0;
	virtual double GetOutputEfficiency() = 0;
	virtual double GetBaseProduction() = 0;

public:
	ISource(ProductType type, double OutputAmount, double startCash, int workforceCapacity = 5000, double payoutPercent = 0.25) :
		IBudget(startCash),
		IProductType(type),
		workforceCapacity(workforceCapacity),
		payoutPercent(payoutPercent),
		OutputAmount(OutputAmount)
	{

	};
	void AddWorker(std::shared_ptr<Pop> worker);
	void AddOwner(std::shared_ptr<Pop> owner);
	virtual void Payout() = 0;
	void Produce();
	~ISource()
	{
		workers.clear();
	}
};

#endif // SOURCE_H
