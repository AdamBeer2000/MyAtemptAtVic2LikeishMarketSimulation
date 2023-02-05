#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H
#include "IProductType.h"
#include "ISource.h"
#include "singletonworldmarket.h"
#include "IProductType.h"
#include "IBudget.h"
#include "PlaceholderDEFINES.h"
#include "Aristocrat.h"

class ResourceGatheringOperation :public ISource
{
protected:
	std::vector<std::shared_ptr<Pop>> workers;
public:
	ResourceGatheringOperation(ProductType sourceType, PopType workerType, double outputamount, int workforceCapacity) :
		ISource(sourceType, workerType, outputamount, workforceCapacity)
	{

	}

	virtual unsigned int JobOffers()const override
	{
		return FactorySizeBase - GetWorkforceSize();
	}

	virtual void AddWorker(std::shared_ptr<Pop> worker)override
	{
		if (GetWorkforceSize() + worker.get()->GetPopSize() > FactorySizeBase * 5000)
			throw "workforceCapacity exceeded";
		worker.get()->SetUnemploed(false, myProductType);
		workers.push_back(worker);
	}

	void Produce()override
	{
		const double BaseProduction = GetBaseProduction();
		const double Throughput = GetThroughput();
		const double OutputEfficiency = GetOutputEfficiency();
		const double Production = BaseProduction * Throughput * OutputEfficiency;
		if (Production <= 0)return;
		ProductStorage p = ProductStorage(myProductType, Production, this);

		SingletonWorldMarket::getInstance()->AddToMarket(p);
	}

	void Payout()override
	{
		if (income <= 0)return;
		unsigned int ownerPopSize = GetOwnerbaseSize();
		unsigned int workerPopSize = GetWorkforceSize();

		double income4owners = income * 2.0 * ownerPopSize / workerPopSize;
		if (income4owners > 0.5 * income)
			income4owners = 0.5 * income;

		double income4workers = income - income4owners;

		double salary = income4workers / workerPopSize;
		double profit = income4owners / ownerPopSize;

		for (std::shared_ptr<Pop> p : workers)
		{
			const double salary4pop = salary * p.get()->GetPopSize();
			p.get()->Income(salary4pop);
		}

		for (std::shared_ptr<Pop> p : owners)
		{
			const double profit4pops = profit * p.get()->GetPopSize();
			p.get()->Income(profit4pops);
		}

		Expense(income4workers);
		income = 0;
	}

	void Print()const
	{
		std::cout << "RGO Type: " << myProductType << " Money:" << IBudget::myBudget << std::endl;
		std::cout << "Workers : " << std::endl;
		for (auto w : workers)
		{
			w.get()->Print();
		}
		std::cout << "Owners : " << std::endl;
		for (auto o : owners)
		{
			o.get()->Print();
		}
		std::cout << std::endl;
	}

	double GetThroughput()const
	{
		double modifiers = (1 + RGOThroughputEfficiencyModifiers - WarExhaustion) * OverseaPenalty;
		double workforce = GetWorkforceSize();
		double Throughput = (workforce / FactorySizeBase) * modifiers;
		return Throughput;
	}

	double GetOutputEfficiency()const
	{

		auto ownersSize = GetOwnerbaseSize();
		auto workersSize = GetWorkforceSize();
		if (workersSize == 0)return 0;

		double aristocratpercent = ((double)ownersSize / (double)workersSize + ownersSize);
		if ((double)workersSize + ownersSize == 0)
		{
			aristocratpercent = 0;
		}
		double OutputEfficiency = 1 + aristocratpercent + RGOOutputEfficiencyModifiers + Terrain + ProvinceInfrastructure * (1 + MobilizedPenalty);
		return OutputEfficiency;
	}

	double GetBaseProduction()const
	{
		double BaseProduction = ProvinceSize * (1 + Terrain + RGOSizeModifiers) * OutputAmount;
		return BaseProduction;
	}

	unsigned int GetWorkforceSize()const
	{
		return std::accumulate(workers.begin(), workers.end(), 0, [](int accumulator, std::shared_ptr<Pop> p) {return accumulator + p.get()->GetPopSize(); });
	}

	void Income(double a)override
	{
		IBudget::Income(a);
	}

	~ResourceGatheringOperation()
	{
		workers.clear();
	}
};

#endif // SOURCE_H
