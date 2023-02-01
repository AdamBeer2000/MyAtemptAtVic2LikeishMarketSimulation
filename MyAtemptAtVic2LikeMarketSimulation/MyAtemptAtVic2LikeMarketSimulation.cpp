#include <iostream>
#include "SingletonPopMGR.h"
#include "SingletonProductionMGR.h"

int main()
{
	auto market = SingletonWorldMarket::getInstance();
	auto popmgr = SingletonPopMGR::GetInstance();
	auto prodmgr = SingletonProductionMGR::GetInstance();

	auto rgo1 = prodmgr->CreateCottonFarm(3600);
	auto rgo2 = prodmgr->CreateGrainFarm(5400);
	auto rgo3 = prodmgr->CreateFruitFarm(500);

	auto sf = popmgr->CreateFarmer(4000);

	popmgr->ArrangeUnenployedPops();

	auto sa = popmgr->CreateAristocrat(300);

	rgo1->AddOwner(sa);

	prodmgr->Produce();

	popmgr->Iteration();

	prodmgr->PayOut();

	popmgr->Iteration();

	popmgr->Print();

	popmgr->ArrangeUnenployedPops();

	std::cout << "Hello World!\n";
}