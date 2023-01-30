// MyAtemptAtVic2LikeMarketSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "factory.h"
#include "mainwindow.h"
#include "resurcemine.h"
#include "need.h"
#include "Pop.h"
#include "Farmer.h"
int main()
{
	ResourceGatheringOperation* wm = new ResourceGatheringOperation(ProductType::grain, 100);
	auto instance = SingletonWorldMarket::getInstance();
	std::vector<std::shared_ptr<Farmer> > farmers = std::vector<std::shared_ptr<Farmer> >();

	for (int i = 0; i < 10; i++)
	{
		auto sf = std::make_shared<Farmer>();
		wm->AddWorker(sf);
		farmers.push_back(sf);
	}
	wm->Produce();
	wm->Print();

	for (auto f : farmers)
	{
		f->Restock();
	}

	wm->Print();

	for (auto f : farmers)
	{
		f->Consume();
	}

	wm->Print();
	wm->Payout();
	wm->Print();

	/*
	std::vector<std::shared_ptr<Need>> beerNeeds = std::vector<std::shared_ptr<Need>>();
	beerNeeds.push_back(std::make_shared<Need>(ProductType::grain, 10, 100));
	Factory* beerF = new Factory(ProductType::beer, 10, beerNeeds);

	std::map<ProductType, std::shared_ptr<Need>> farmerNeeds = std::map<ProductType, std::shared_ptr<Need>>();
	farmerNeeds.insert({ ProductType::beer ,std::make_shared<Need>(ProductType::beer, 10, 0, 10) });
	Pop* farmer = new Pop(PopType::farmer, 100, farmerNeeds);

	wm->Produce();
	beerF->Print();
	beerF->Produce();
	beerF->Print();

	farmer->Print();
	farmer->Restock();
	farmer->Print();
	farmer->Consume();
	farmer->Print();

	beerF->Print();
	beerF->Restock();
	beerF->Print();
	*/
	std::cout << "Hello World!\n";
}