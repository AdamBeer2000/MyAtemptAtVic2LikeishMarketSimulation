// MyAtemptAtVic2LikeMarketSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "factory.h"
#include "mainwindow.h"
#include "resurcemine.h"
#include "need.h"

int main()
{
	ISource* wm = new ResourceMine(ProductType::wheat, 100);
	ISource* gm = new ResourceMine(ProductType::greap, 100);
	std::vector<std::shared_ptr<Need>> beerNeeds = std::vector<std::shared_ptr<Need>>();
	beerNeeds.push_back(std::make_shared<Need>(ProductType::wheat, 10, 100));
	Factory* beerF = new Factory(ProductType::beer, 10, beerNeeds);
	wm->Produce();

	beerF->Print();
	//SingletonWorldMarket::getInstance()->Print();
	beerF->Produce();
	beerF->Print();
	beerF->Restock();
	beerF->Print();
	// SingletonWorldMarket::getInstance()->Print();

	std::cout << "Hello World!\n";
}