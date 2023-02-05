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

std::shared_ptr<CoalMine> ProductionMGR::CreateCoalMine(int capacity)
{
	std::shared_ptr<CoalMine> farm = std::make_shared<CoalMine>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, CoalMine>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<IronMine> ProductionMGR::CreateIronMine(int capacity)
{
	std::shared_ptr<IronMine> farm = std::make_shared<IronMine>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, IronMine>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<SulphurMine> ProductionMGR::CreateSulphurMine(int capacity)
{
	std::shared_ptr<SulphurMine> farm = std::make_shared<SulphurMine>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, SulphurMine>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<PreciousMetalMine> ProductionMGR::CreatePreciousMetalMine(int capacity)
{
	std::shared_ptr<PreciousMetalMine> farm = std::make_shared<PreciousMetalMine>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, PreciousMetalMine>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<OilMine> ProductionMGR::CreateOilMine(int capacity)
{
	std::shared_ptr<OilMine> farm = std::make_shared<OilMine>(capacity);
	std::shared_ptr<ISource> farmptr = std::static_pointer_cast<ISource, OilMine>(farm);
	sources.push_back(farmptr);
	return farm;
}

std::shared_ptr<ResourceGatheringOperation> ProductionMGR::Create(ProductType productType, int capacity)
{
	switch (productType)
	{
	case grain: return CreateGrainFarm(capacity);
	case timber:return CreateTimberFarm(capacity);
	case cattle:return CreateCattleFarm(capacity);
	case cotton:return CreateCottonFarm(capacity);
	case coffee:return CreateCoffeFarm(capacity);
	case dye:return CreateDyeFarm(capacity);
	case fish:return CreateFishFarm(capacity);
	case fruit: return CreateFruitFarm(capacity);
	case opium:return CreateOpiumFarm(capacity);
	case rubber:return CreateRubberFarm(capacity);
	case wool:return CreateWoolFarm(capacity);
	case silk:return CreateSilkFarm(capacity);
	case tea:return CreateTeaFarm(capacity);
	case tobaco:return CreateTobbacoFarm(capacity);
	case tropical_wood: return CreateTropicalWoodFarm(capacity);
	case coal:return CreateCoalMine(capacity);
	case iron: return CreateIronMine(capacity);
	case sulphur: return CreateSulphurMine(capacity);
	case precious_metal: return	CreatePreciousMetalMine(capacity);
	case oil:return CreateOilMine(capacity);
	}
	throw "";
}

std::vector<std::shared_ptr<ISource>> ProductionMGR::GetAviableJobs(PopType type)
{
	auto srcs = std::vector<std::shared_ptr<ISource>>();
	for (auto src : sources)
	{
		if (src.get()->JobOffers() > 0 && src.get()->CanIWorkHere(type))
			srcs.push_back(src);
	}

	return srcs;
}
