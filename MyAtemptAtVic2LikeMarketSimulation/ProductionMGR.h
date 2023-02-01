#pragma once
#include "Farms.h"

class ProductionMGR
{

private:
	std::vector < std::shared_ptr<ISource> >sources = std::vector < std::shared_ptr<ISource> >();
public:
	void Iteration();
	void Produce();
	void PayOut();
	std::shared_ptr<GrainFarm> CreateGrainFarm(int capacity = 5000);
	std::shared_ptr<TimberFarm> CreateTimberFarm(int capacity = 5000);
	std::shared_ptr<CattleFarm> CreateCattleFarm(int capacity = 5000);
	std::shared_ptr<CottonFarm> CreateCottonFarm(int capacity = 5000);
	std::shared_ptr<CoffeFarm> CreateCoffeFarm(int capacity = 5000);
	std::shared_ptr<DyeFarm> CreateDyeFarm(int capacity = 5000);
	std::shared_ptr<FishFarm> CreateFishFarm(int capacity = 5000);
	std::shared_ptr<FruitFarm> CreateFruitFarm(int capacity = 5000);
	std::shared_ptr<OpiumFarm> CreateOpiumFarm(int capacity = 5000);
	std::shared_ptr<RubberFarm> CreateRubberFarm(int capacity = 5000);
	std::shared_ptr<WoolFarm> CreateWoolFarm(int capacity = 5000);
	std::shared_ptr<SilkFarm> CreateSilkFarm(int capacity = 5000);
	std::shared_ptr<TeaFarm> CreateTeaFarm(int capacity = 5000);
	std::shared_ptr<TobbacoFarm> CreateTobbacoFarm(int capacity = 5000);
	std::shared_ptr<TropicalWoodFarm> CreateTropicalWoodFarm(int capacity = 5000);

	std::vector < std::shared_ptr<ISource> > GetAviableJobs(PopType type);

	~ProductionMGR()
	{
		sources.clear();
	}
};
