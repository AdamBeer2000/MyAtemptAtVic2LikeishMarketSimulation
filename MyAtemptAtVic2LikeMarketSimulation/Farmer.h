#pragma once
#include "Pop.h"

class Farmer :public Pop
{
public:
	Farmer() :Pop(PopType::farmer, 5)
	{
		AddNeed(Need(grain, 2.5, 0, 2.5));
		AddNeed(Need(fish, 1, 0, 1));
		AddNeed(Need(fruit, 1, 0, 1));
		AddNeed(Need(wool, 1, 0, 1));
		AddNeed(Need(cattle, 0.75, 0, 0.75));
	}
	~Farmer()
	{
		std::cout << "deleted \n";
	}
};