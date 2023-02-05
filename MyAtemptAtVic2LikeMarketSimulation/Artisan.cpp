#include "Artisan.h"

double Artisan::GetThroughput()const
{
	return 1.0;
}

double Artisan::GetOutputEfficiency()const
{
	return 1.0;
}

double Artisan::GetBaseProduction()const
{
	return OutputAmount;
}

unsigned int Artisan::JobOffers()
{
	return 0;
}

void Artisan::AddWorker(std::shared_ptr<Pop> worker)
{
}

void Artisan::Payout()
{

}

unsigned int Artisan::JobOffers() const
{
	return 0;
}
