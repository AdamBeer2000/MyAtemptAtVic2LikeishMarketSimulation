#include "factory.h"

double Factory::GetThroughput() const
{
	return (craftmancount / (FactorySizeBase * 10000)) *
		(1 + FacktoryThroughputTecs + AVGInfrastructureInState * 0.16) *
		(1 + LocalFactoryThroughput);
}

double Factory::GetOutputEfficiency() const
{
	const double NumberOfCapitalists = GetOwnerbaseSize();
	return 1 - ((1.5 * (clerkcount / TotalPopulationOfState)) + FacktoryEfficiencyTecs + EconomyEfficiencyTecs);
}

double Factory::GetInputEfficiency() const
{
	const double NumberOfCapitalists = GetOwnerbaseSize();
	return 1 - ((2.5 * (NumberOfCapitalists / TotalPopulationOfState)) - FacktoryEfficiencyTecs - EconomyEfficiencyTecs);
}

double Factory::GetBaseProduction() const
{
	return OutputAmount;
}

double Factory::GetInput(double baseinput) const
{
	return FactorySizeBase * baseinput * GetThroughput() * GetInputEfficiency();
}

double Factory::GetOutput() const
{
	return FactorySizeBase * GetBaseProduction() * GetThroughput() * GetOutputEfficiency();
}

void Factory::IsBankrupt() const
{
	income < 1000;
}

bool Factory::CanIWorkHere(PopType p) const
{
	return p == craftman || p == clerk;
}

unsigned int Factory::JobOffers()
{
	return FactorySizeBase - GetWorkforceSize();
}

void Factory::AddWorker(std::shared_ptr<Pop> worker)
{
	if (GetWorkforceSize() + worker.get()->GetPopSize() > FactorySizeBase)
		throw "workforceCapacity exceeded";
	if (worker.get()->getPopType() == craftman)
		craftmancount += worker.get()->GetPopSize();
	if (worker.get()->getPopType() == clerk)
		clerkcount += worker.get()->GetPopSize();

	worker.get()->SetUnemploed(false, myProductType);
	workers.push_back(worker);
}

void Factory::Payout()
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
