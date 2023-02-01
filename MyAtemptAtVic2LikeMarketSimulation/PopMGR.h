#pragma once
#include "Pop.h"
#include "Farmer.h"
#include "Aristocrat.h"
#include "Labourer.h"
#include "SingletonProductionMGR.h"
class PopMGR
{

private:
	std::vector < std::shared_ptr<Pop>> population = std::vector < std::shared_ptr<Pop>>();

	void MergePops();
	void ReCalcFullfilment();

	std::vector<std::shared_ptr<Pop>> GetUnenployedPops() const;
public:
	void Iteration();
	void ArrangeUnenployedPops();
	std::shared_ptr<Farmer> CreateFarmer(unsigned int PopSize);
	std::shared_ptr<Aristocrat> CreateAristocrat(unsigned int PopSize);
	std::shared_ptr<Labourer> CreateLabourer(unsigned int PopSize);

	void Print()const;

	~PopMGR()
	{
		population.clear();
	}
};

