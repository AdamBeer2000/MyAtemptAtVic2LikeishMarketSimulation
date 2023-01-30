#include "ISource.h"

void ISource::AddWorker(std::shared_ptr<Pop> worker)
{
	if (workforceCapacity == workers.size())
		throw "workforceCapacity exceeded";

	workers.push_back(worker);
}

void ISource::Payout()
{
	double income2share = IBudget::income * payoutPercent;
	double salary = income2share / workers.size();

	for (auto p : workers)
	{
		p.get()->Income(salary);
	}

	Expense(income2share);
	IBudget::income = 0;
}

double ISource::GetCapacity() const
{
	return (workers.size() / workforceCapacity) * baseCapacity;
}
