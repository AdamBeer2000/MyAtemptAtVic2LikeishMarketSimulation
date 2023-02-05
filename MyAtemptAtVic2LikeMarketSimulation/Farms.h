#pragma once
#include "ResourceGatheringOperation.h"
#include "Farmer.h"

class GrainFarm :public ResourceGatheringOperation
{
public:
	GrainFarm(int workforceCap) :ResourceGatheringOperation(grain, farmer, 1.8, workforceCap)
	{

	}
};

class TimberFarm :public ResourceGatheringOperation
{
public:
	TimberFarm(int workforceCap) :ResourceGatheringOperation(timber, farmer, 8.0, workforceCap)
	{

	}
};

class CattleFarm :public ResourceGatheringOperation
{
public:
	CattleFarm(int workforceCap) :ResourceGatheringOperation(cattle, farmer, 1.8, workforceCap)
	{

	}
};

class CottonFarm :public ResourceGatheringOperation
{
public:
	CottonFarm(int workforceCap) :ResourceGatheringOperation(cotton, farmer, 2.2, workforceCap)
	{

	}
};

class CoffeFarm :public ResourceGatheringOperation
{
public:
	CoffeFarm(int workforceCap) :ResourceGatheringOperation(coffee, farmer, 1.5, workforceCap)
	{

	}
};

class DyeFarm :public ResourceGatheringOperation
{
public:
	DyeFarm(int workforceCap) :ResourceGatheringOperation(dye, farmer, 0.22, workforceCap)
	{

	}
};

class FishFarm :public ResourceGatheringOperation
{
public:
	FishFarm(int workforceCap) :ResourceGatheringOperation(fish, farmer, 2.2, workforceCap)
	{

	}
};

class FruitFarm :public ResourceGatheringOperation
{
public:
	FruitFarm(int workforceCap) :ResourceGatheringOperation(fruit, farmer, 2.8, workforceCap)
	{

	}
};

class OpiumFarm :public ResourceGatheringOperation
{
public:
	OpiumFarm(int workforceCap) :ResourceGatheringOperation(opium, farmer, 0.7, workforceCap)
	{

	}
};

class RubberFarm :public ResourceGatheringOperation
{
public:
	RubberFarm(int workforceCap) :ResourceGatheringOperation(rubber, farmer, 0.75, workforceCap)
	{

	}
};

class WoolFarm :public ResourceGatheringOperation
{
public:
	WoolFarm(int workforceCap) :ResourceGatheringOperation(wool, farmer, 5, workforceCap)
	{

	}
};

class SilkFarm :public ResourceGatheringOperation
{
public:
	SilkFarm(int workforceCap) :ResourceGatheringOperation(silk, farmer, 0.25, workforceCap)
	{

	}
};

class TeaFarm :public ResourceGatheringOperation
{
public:
	TeaFarm(int workforceCap) :ResourceGatheringOperation(tea, farmer, 1.75, workforceCap)
	{

	}
};

class TobbacoFarm :public ResourceGatheringOperation
{
public:
	TobbacoFarm(int workforceCap) :ResourceGatheringOperation(tobaco, farmer, 2.5, workforceCap)
	{

	}
};

class TropicalWoodFarm :public ResourceGatheringOperation
{
public:
	TropicalWoodFarm(int workforceCap) :ResourceGatheringOperation(tropical_wood, farmer, 4, workforceCap)
	{

	}
};