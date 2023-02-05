#pragma once
#include "singletonworldmarket.h"
#include "SingletonPopMGR.h"
#include "SingletonProductionMGR.h"
#include "Converters.h"
class Simulator
{
	Market* market = SingletonWorldMarket::getInstance();
	PopMGR* popmgr = SingletonPopMGR::GetInstance();
	ProductionMGR* prodmgr = SingletonProductionMGR::GetInstance();
public:
	Simulator()
	{
		auto allrgo = GetAllRGO();
		auto product = GetAllArtisanProduct();

		//create farmer pops
		//pop size
		popmgr->CreateFarmer(100000);
		auto aristocrat = popmgr->CreateAristocrat(1000);

		//create rgo
		//rgo type grain,silk etc
		//rgo size 1000,2000,3000 etc.. (maximum pop size can work there)
		//the farmer pops will be arranged automaticly by PopMGR
		auto rgo1 = prodmgr->Create(grain, 50000);
		rgo1.get()->AddOwner(aristocrat);

		//create artisan
		//product type type
		popmgr->CreateArtisan(liquor, 5000);

		//factores partciali implemented but dosnt work yet
	}

	void Iteration()
	{
		popmgr->ArrangeUnenployedPops();
		prodmgr->Produce();
		popmgr->ReCalcFullfilment();
		prodmgr->PayOut();
		market->RecalcPrices();
		popmgr->Print();
	}

	~Simulator()
	{
		delete market;
		delete popmgr;
		delete prodmgr;
	}

};