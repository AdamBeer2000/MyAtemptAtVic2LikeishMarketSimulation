
#include "ProductCreator.h"

double Artisan::GetThroughput()
{
	return 1.0;
}

double Artisan::GetOutputEfficiency()
{
	return 1.0;
}

double Artisan::GetBaseProduction()
{
	return OutputAmount;
}

unsigned int Artisan::JobOffers()
{
	return 1;
}

void Artisan::AddWorker(std::shared_ptr<Pop> worker)
{
}

void Artisan::Payout()
{
}
