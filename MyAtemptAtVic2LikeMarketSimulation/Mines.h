#pragma once
#include "Labourer.h"
#include "ResourceGatheringOperation.h"

class CoalMine :public ResourceGatheringOperation
{
public:
	CoalMine(int workforceCap) :ResourceGatheringOperation(coal, laborel, 2.4, workforceCap)
	{

	}
};

class IronMine :public ResourceGatheringOperation
{
public:
	IronMine(int workforceCap) :ResourceGatheringOperation(iron, laborel, 1.8, workforceCap)
	{

	}
};

class SulphurMine :public ResourceGatheringOperation
{
public:
	SulphurMine(int workforceCap) :ResourceGatheringOperation(sulphur, laborel, 2, workforceCap)
	{

	}
};

class PreciousMetalMine :public ResourceGatheringOperation
{
public:
	PreciousMetalMine(int workforceCap) :ResourceGatheringOperation(precious_metal, laborel, 2, workforceCap)
	{

	}
};

class OilMine :public ResourceGatheringOperation
{
public:
	OilMine(int workforceCap) :ResourceGatheringOperation(oil, laborel, 1, workforceCap)
	{

	}
};