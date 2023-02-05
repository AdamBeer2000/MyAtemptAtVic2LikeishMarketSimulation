#include <iostream>
#include "SImulator.h"
int main()
{
	Simulator* s = new Simulator();
	s->Iteration();


	for (int i = 0; i <= 35; i++)
	{
		std::cout << "ITER" << i << "\n";
		s->Iteration();
	}

	SingletonWorldMarket::getInstance()->WriteHist();

}