#pragma once
#include "Pop.h"
#include "Farmer.h"
#include "Aristocrat.h"
#include "Labourer.h"
#include "SingletonProductionMGR.h"
#include "Artisan.h"
class PopMGR
{

private:
	std::vector < std::shared_ptr<Pop>> population = std::vector < std::shared_ptr<Pop>>();



	std::vector<std::shared_ptr<Pop>> GetUnenployedPops() const;
public:

	void ArrangeUnenployedPops();
	void MergePops();
	void ReCalcFullfilment();
	std::shared_ptr<Farmer> CreateFarmer(unsigned int PopSize);
	std::shared_ptr<Aristocrat> CreateAristocrat(unsigned int PopSize);
	std::shared_ptr<Labourer> CreateLabourer(unsigned int PopSize);
	std::shared_ptr<Artisan> CreateArtisan(ProductType type, unsigned int PopSize);

	void Print()const;

	~PopMGR()
	{
		population.clear();
	}
};

