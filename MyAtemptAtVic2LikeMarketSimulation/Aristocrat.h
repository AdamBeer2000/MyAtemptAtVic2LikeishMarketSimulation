#pragma once
#include "Pop.h"
class Aristocrat :public Pop
{
public:
	Aristocrat() :Pop(PopType::aristocrat, 5)
	{
		AddNeed(PopNeed(grain, 2.5));
		AddNeed(PopNeed(fish, 1));
		AddNeed(PopNeed(fruit, 1));
		AddNeed(PopNeed(wool, 1));
		AddNeed(PopNeed(cattle, 0.75));
	}
};