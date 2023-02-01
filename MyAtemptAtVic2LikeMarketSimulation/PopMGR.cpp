#include "PopMGR.h"

void PopMGR::MergePops()
{

}

void PopMGR::ReCalcFullfilment()
{
	for (auto p : population)
	{
		p.get()->CalcNeedFulfillment();
	}
}

void PopMGR::ArrangeUnenployedPops()
{
	auto unemployedpops = GetUnenployedPops();
	auto prod = SingletonProductionMGR::GetInstance();
	auto addAfter = std::vector < std::shared_ptr<Pop>>();

	for (auto pop : unemployedpops)
	{
		auto jobs = prod->GetAviableJobs(pop.get()->getPopType());
		auto bestfit = std::min_element(jobs.begin(), jobs.end(),
			[pop](const std::shared_ptr<ISource> a, const std::shared_ptr<ISource> b)
			{
				return std::abs((double)a.get()->JobOffers() - pop.get()->GetPopSize()) < std::abs((double)b.get()->JobOffers() - pop.get()->GetPopSize());
			});

		std::shared_ptr<ISource> best = *bestfit;
		auto jobOfferC = best.get()->JobOffers();
		auto popsize = pop.get()->GetPopSize();
		if (jobOfferC == popsize || jobOfferC > popsize)
		{
			best.get()->AddWorker(pop);
		}
		else
		{
			auto fragment = pop.get()->fragment(popsize - jobOfferC);
			best.get()->AddWorker(pop);
			addAfter.push_back(fragment);
			pop.get()->SetUnemploed(false);
		}
	}

	for (auto add : addAfter)
	{
		population.push_back(add);
	}
}

std::vector<std::shared_ptr<Pop>>PopMGR::GetUnenployedPops() const
{
	auto pops = std::vector<std::shared_ptr<Pop>>();
	for (auto pop : population)
	{
		if (pop.get()->IsUnemployed())
			pops.push_back(pop);
	}
	return pops;
}

void PopMGR::Iteration()
{
	ReCalcFullfilment();
	MergePops();
}

std::shared_ptr<Farmer> PopMGR::CreateFarmer(unsigned int PopSize)
{
	auto farmer = std::make_shared<Farmer>(PopSize);
	population.push_back(farmer);
	return farmer;
}

std::shared_ptr<Aristocrat> PopMGR::CreateAristocrat(unsigned int PopSize)
{
	auto aristocrat = std::make_shared<Aristocrat>(PopSize);
	population.push_back(aristocrat);
	return aristocrat;
}

std::shared_ptr<Labourer> PopMGR::CreateLabourer(unsigned int PopSize)
{
	auto labourer = std::make_shared<Labourer>(PopSize);
	population.push_back(labourer);
	return labourer;
}

void PopMGR::Print() const
{
	for (auto p : population)
	{
		p.get()->Print();
	}
}
