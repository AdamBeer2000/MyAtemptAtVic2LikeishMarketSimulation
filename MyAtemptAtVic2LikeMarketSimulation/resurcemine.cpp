#include "resurcemine.h"
#include "PlaceholderDEFINES.h"

ResourceGatheringOperation::ResourceGatheringOperation(ProductType sourceType, double capacity, double startCash) :
	ISource(sourceType, capacity, startCash), IBudget(startCash)
{

}

void ResourceGatheringOperation::Payout()
{
	double income4owners = IBudget::income * 2 * owners.size() / workers.size();
	if (income4owners > 0.5 * IBudget::income)
		income4owners = 0.5 * IBudget::income;

	double income2share = IBudget::income - income4owners;

	double salary = income2share / workers.size();
	double profit = income4owners / owners.size();

	for (auto p : workers)
	{
		p.get()->Income(salary);
	}
	for (auto p : owners)
	{
		p.get()->Income(profit);
	}

	IBudget::Expense(income2share);
	IBudget::income = 0;
}

void ResourceGatheringOperation::Print()const
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

double ResourceGatheringOperation::GetThroughput()
{
	double modifiers = (1 + RGOThroughputEfficiencyModifiers - WarExhaustion) * OverseaPenalty;
	double workforce = workers.size();
	double Throughput = (workforce / workforceCapacity) * modifiers;
	return Throughput;
}

double ResourceGatheringOperation::GetOutputEfficiency()
{
	double OutputEfficiency = 1 + (owners.size() / (workers.size() + owners.size())) + RGOOutputEfficiencyModifiers + Terrain + ProvinceInfrastructure * (1 + MobilizedPenalty);
	return OutputEfficiency;
}

double ResourceGatheringOperation::GetBaseProduction()
{
	double BaseProduction = ProvinceSize * (1 + Terrain + RGOSizeModifiers) * OutputAmount;
	return BaseProduction;
}
