#pragma once
#pragma once
#include "Pop.h"

class Labourer :public Pop
{
public:
	Labourer(unsigned int PopSize) :Pop(PopType::laborel, 0.001, PopSize)
	{
		AddNeed(PopNeed(grain, 2.5));
		AddNeed(PopNeed(fish, 1));
		AddNeed(PopNeed(fruit, 1));
		AddNeed(PopNeed(wool, 1));
		AddNeed(PopNeed(cattle, 0.75));
	}
};