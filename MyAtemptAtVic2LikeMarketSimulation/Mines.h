#pragma once
#include "Labourer.h"
#include "resurcemine.h"
/*
Coal.png Coal	175	Mine
Iron.png Iron	112	Mine
Sulphur.png Sulphur	35	Mine
Precious metal.png Precious Metal	1	Mine
Resource oil.png Oil	0	Mine
*/

class CoalMine :ResourceGatheringOperation
{
public:
	CoalMine(int workforceCap) :ResourceGatheringOperation(coal, laborel, 2.4, workforceCap)
	{

	}
};

class IronMine :ResourceGatheringOperation
{
public:
	IronMine(int workforceCap) :ResourceGatheringOperation(iron, laborel, 1.8, workforceCap)
	{

	}
};

class SulphurMine :ResourceGatheringOperation
{
public:
	SulphurMine(int workforceCap) :ResourceGatheringOperation(sulphur, laborel, 2, workforceCap)
	{

	}
};

class PreciousMetalMine :ResourceGatheringOperation
{
public:
	PreciousMetalMine(int workforceCap) :ResourceGatheringOperation(precious_metal, laborel, 2, workforceCap)
	{

	}
};

class OilMine :ResourceGatheringOperation
{
public:
	OilMine(int workforceCap) :ResourceGatheringOperation(oil, laborel, 1, workforceCap)
	{

	}
};