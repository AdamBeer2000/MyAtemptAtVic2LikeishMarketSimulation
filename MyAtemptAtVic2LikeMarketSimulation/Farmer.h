#pragma once
#include "Pop.h"

class Farmer :public Pop
{
public:
	Farmer() :Pop(PopType::farmer, 5)
	{
		AddNeed(PopNeed(grain, 2.5));
		AddNeed(PopNeed(fish, 1));
		AddNeed(PopNeed(fruit, 1));
		AddNeed(PopNeed(wool, 1));
		AddNeed(PopNeed(cattle, 0.75));
	}

};