#include "ProductionMGR.h"

void ProductionMGR::Iteration()
{
	Produce();
	PayOut();
}

void ProductionMGR::Produce()
{
	for (auto s : sources)
	{
		s.get()->Produce();
	}
}

void ProductionMGR::PayOut()
{
	for (auto s : sources)
	{
		s.get()->Payout();
	}
}

std::shared_ptr<GrainFarm> ProductionMGR::CreateGrainFarm(int capacity)
{
	std::shared_ptr<GrainFarm> farm = std::make_shared<GrainFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, GrainFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<TimberFarm> ProductionMGR::CreateTimberFarm(int capacity)
{
	std::shared_ptr<TimberFarm> farm = std::make_shared<TimberFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, TimberFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<CattleFarm> ProductionMGR::CreateCattleFarm(int capacity)
{
	std::shared_ptr<CattleFarm> farm = std::make_shared<CattleFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, CattleFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<CottonFarm> ProductionMGR::CreateCottonFarm(int capacity)
{
	std::shared_ptr<CottonFarm> farm = std::make_shared<CottonFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, CottonFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<CoffeFarm> ProductionMGR::CreateCoffeFarm(int capacity)
{
	std::shared_ptr<CoffeFarm> farm = std::make_shared<CoffeFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, CoffeFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<DyeFarm> ProductionMGR::CreateDyeFarm(int capacity)
{
	std::shared_ptr<DyeFarm> farm = std::make_shared<DyeFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, DyeFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<FishFarm> ProductionMGR::CreateFishFarm(int capacity)
{
	std::shared_ptr<FishFarm> farm = std::make_shared<FishFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, FishFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<FruitFarm> ProductionMGR::CreateFruitFarm(int capacity)
{
	std::shared_ptr<FruitFarm> farm = std::make_shared<FruitFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, FruitFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<OpiumFarm> ProductionMGR::CreateOpiumFarm(int capacity)
{
	std::shared_ptr<OpiumFarm> farm = std::make_shared<OpiumFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, OpiumFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<RubberFarm> ProductionMGR::CreateRubberFarm(int capacity)
{
	std::shared_ptr<RubberFarm> farm = std::make_shared<RubberFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, RubberFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<WoolFarm> ProductionMGR::CreateWoolFarm(int capacity)
{
	std::shared_ptr<WoolFarm> farm = std::make_shared<WoolFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, WoolFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<SilkFarm> ProductionMGR::CreateSilkFarm(int capacity)
{
	std::shared_ptr<SilkFarm> farm = std::make_shared<SilkFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, SilkFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<TeaFarm> ProductionMGR::CreateTeaFarm(int capacity)
{
	std::shared_ptr<TeaFarm> farm = std::make_shared<TeaFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, TeaFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<TobbacoFarm> ProductionMGR::CreateTobbacoFarm(int capacity)
{
	std::shared_ptr<TobbacoFarm> farm = std::make_shared<TobbacoFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, TobbacoFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<TropicalWoodFarm> ProductionMGR::CreateTropicalWoodFarm(int capacity)
{
	std::shared_ptr<TropicalWoodFarm> farm = std::make_shared<TropicalWoodFarm>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, TropicalWoodFarm>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::vector<std::shared_ptr<ISource>> ProductionMGR::GetAviableJobs(PopType type)
{
	auto srcs = std::vector<std::shared_ptr<ISource>>();
	for (auto src : sources)
	{
		if (src.get()->JobOffers() > 0 && src.get()->GetWorkerType() == type)
			srcs.push_back(src);
	}

	return srcs;
}
