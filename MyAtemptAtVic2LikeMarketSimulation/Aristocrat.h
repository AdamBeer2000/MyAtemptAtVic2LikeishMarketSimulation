#pragma once
#include "Pop.h"
class Aristocrat :public Pop
{
public:
	Aristocrat(unsigned int PopSize) :Pop(PopType::aristocrat, 1.2 * PopSize, PopSize), IBudget(0.012 * PopSize)
	{
		AddNeed(PopNeed(grain, 2.5));
		AddNeed(PopNeed(fish, 1));
		AddNeed(PopNeed(fruit, 1));
		AddNeed(PopNeed(wool, 1));
		AddNeed(PopNeed(cattle, 0.75));

		AddNeed(PopNeed(paper, 10, PopNeed::evryday));
		AddNeed(PopNeed(tobaco, 10, PopNeed::evryday));
		AddNeed(PopNeed(wine, 10, PopNeed::evryday));
		AddNeed(PopNeed(coffee, 5, PopNeed::evryday));
		AddNeed(PopNeed(luxury_clothes, 3, PopNeed::evryday));
		AddNeed(PopNeed(luxury_furniture, 3, PopNeed::evryday));
		AddNeed(PopNeed(coal, 1, PopNeed::evryday));

		AddNeed(PopNeed(automobile, 10, PopNeed::luxury));
		AddNeed(PopNeed(fuel, 10, PopNeed::luxury));
		AddNeed(PopNeed(radio, 10, PopNeed::luxury));
		AddNeed(PopNeed(telephone, 10, PopNeed::luxury));
		AddNeed(PopNeed(aeroplane, 5, PopNeed::luxury));
		AddNeed(PopNeed(clipper, 2, PopNeed::luxury));
		AddNeed(PopNeed(steamer, 2, PopNeed::luxury));
		AddNeed(PopNeed(ammunition, 1, PopNeed::luxury));
		AddNeed(PopNeed(small_arms, 1, PopNeed::luxury));

		unemployed = false;
	}
};