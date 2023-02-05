#ifndef SOURCE_H
#define SOURCE_H
#include "Pop.h"
#include "IBudget.h"
#include "IProductType.h"
#include "singletonworldmarket.h"

class ISource :virtual public IBudget, public IProductType
{
private:

protected:
	double OutputAmount;
	int FactorySizeBase;
	PopType workerType;
	std::vector<std::shared_ptr<Pop>> owners;


	virtual double GetThroughput()const = 0;
	virtual double GetOutputEfficiency()const = 0;
	virtual double GetBaseProduction()const = 0;

public:
	ISource(ProductType type, PopType workerType, double OutputAmount, int FactorySizeBase = 1) :
		IProductType(type),
		workerType(workerType),
		FactorySizeBase(FactorySizeBase),
		OutputAmount(OutputAmount)
	{

	};

	virtual unsigned int JobOffers()const = 0;
	virtual bool CanIWorkHere(PopType p)const
	{
		return p == workerType;
	}

	virtual void AddWorker(std::shared_ptr<Pop> worker) = 0;

	void AddOwner(std::shared_ptr<Pop> owner)
	{
		owner.get()->SetUnemploed(false, myProductType);
		owners.push_back(owner);
	}

	unsigned int GetOwnerbaseSize()const
	{
		return std::accumulate(owners.begin(), owners.end(), 0, [](int accumulator, std::shared_ptr<Pop> p) {return accumulator + p.get()->GetPopSize(); });
	}

	virtual void Payout() = 0;

	virtual void Produce() = 0;


	PopType GetWorkerType()const
	{
		return workerType;
	}

	void Income(double a)override
	{
		IBudget::Income(a);
	}

	~ISource()
	{
		owners.clear();
	}
};

#endif // SOURCE_H
