#include <iostream>
#include "factory.h"
#include "mainwindow.h"
#include "resurcemine.h"
#include "need.h"
#include "Pop.h"
#include "Farmer.h"
#include "Aristocrat.h"

int main()
{
	ResourceGatheringOperation* rgo1 = new ResourceGatheringOperation(ProductType::grain, 100);

	auto instance = SingletonWorldMarket::getInstance();
	std::vector<std::shared_ptr<Pop> > pops = std::vector<std::shared_ptr<Pop>>();

	for (int i = 0; i < 500; i++)
	{
		auto sf = std::make_shared<Farmer>();
		rgo1->AddWorker(sf);
		pops.push_back(sf);
	}
	for (int i = 0; i < 5; i++)
	{
		auto sf = std::make_shared<Aristocrat>();
		rgo1->AddOwner(sf);
		pops.push_back(sf);
	}

	rgo1->Produce();

	for (auto f : pops)
	{
		f.get()->CalcNeedFulfillment();
	}

	rgo1->Payout();

	rgo1->Print();

	delete rgo1;
	std::cout << "Hello World!\n";
}