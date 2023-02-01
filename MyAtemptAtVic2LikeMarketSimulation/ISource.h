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
	PopType workerType;
	std::vector<std::shared_ptr<Pop>> owners;


	virtual double GetThroughput() = 0;
	virtual double GetOutputEfficiency() = 0;
	virtual double GetBaseProduction() = 0;

public:
	ISource(ProductType type, PopType workerType, double OutputAmount, int workforceCapacity = 5000) :
		IProductType(type),
		workerType(workerType),
		workforceCapacity(workforceCapacity),
		OutputAmount(OutputAmount), IBudget(0)
	{

	};

	virtual unsigned int JobOffers()const = 0;

	virtual void AddWorker(std::shared_ptr<Pop> worker) = 0;

	void AddOwner(std::shared_ptr<Pop> owner)
	{
		owners.push_back(owner);
	}

	unsigned int GetOwnerbaseSize()const
	{
		return std::accumulate(owners.begin(), owners.end(), 0, [](int accumulator, std::shared_ptr<Pop> p) {return accumulator + p.get()->GetPopSize(); });
	}

	virtual void Payout() = 0;

	virtual void Produce()
	{
		const double BaseProduction = GetBaseProduction();
		const double Throughput = GetThroughput();
		const double OutputEfficiency = GetOutputEfficiency();
		const double Production = BaseProduction * Throughput * OutputEfficiency;
		if (Production <= 0)return;
		ProductStorage p = ProductStorage(myProductType, Production, this);

		SingletonWorldMarket::getInstance()->AddToMarket(p);
	}

	PopType GetWorkerType()const
	{
		return workerType;
	}

	~ISource()
	{
		owners.clear();
	}
};

#endif // SOURCE_H
