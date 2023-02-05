#pragma once
#include "Pop.h"

class Farmer :public Pop
{
public:
	Farmer(unsigned int PopSize) :Pop(PopType::farmer, 0.01 * PopSize, PopSize), IBudget(0.0025 * PopSize)
	{
		AddNeed(PopNeed(grain, 2.5));
		AddNeed(PopNeed(fish, 1));
		AddNeed(PopNeed(fruit, 1));
		AddNeed(PopNeed(wool, 1));
		AddNeed(PopNeed(cattle, 0.75));

		AddNeed(PopNeed(tea, 4, PopNeed::evryday));
		AddNeed(PopNeed(liquor, 3, PopNeed::evryday));
		AddNeed(PopNeed(regular_clothes, 1.2, PopNeed::evryday));
		AddNeed(PopNeed(furniture, 1.1, PopNeed::evryday));
		AddNeed(PopNeed(coal, 1, PopNeed::evryday));
		AddNeed(PopNeed(fertilizer, 0.5, PopNeed::evryday));

		AddNeed(PopNeed(furniture, 3, PopNeed::luxury));
		AddNeed(PopNeed(regular_clothes, 3, PopNeed::luxury));
		AddNeed(PopNeed(liquor, 1.5, PopNeed::luxury));
		AddNeed(PopNeed(paper, 1, PopNeed::luxury));
		AddNeed(PopNeed(radio, 1, PopNeed::luxury));
		AddNeed(PopNeed(telephone, 1, PopNeed::luxury));
		AddNeed(PopNeed(tobaco, 0.95, PopNeed::luxury));
		AddNeed(PopNeed(automobile, 0.5, PopNeed::luxury));
		AddNeed(PopNeed(coffee, 0.45, PopNeed::luxury));
		AddNeed(PopNeed(fuel, 0.1, PopNeed::luxury));

	}

};