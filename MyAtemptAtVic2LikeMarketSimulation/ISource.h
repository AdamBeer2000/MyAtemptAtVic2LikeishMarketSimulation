#ifndef SOURCE_H
#define SOURCE_H
#include "Pop.h"
#include "IBudget.h"

class ISource :public IBudget
{

private:

protected:
	double baseCapacity;
	int workforceCapacity;
	double payoutPercent;
	std::vector<std::shared_ptr<Pop>> workers;
	virtual void Produce(double ammount) = 0;

public:
	ISource(double baseCapacity, double startCash, int workforceCapacity = 5000, double payoutPercent = 0.25) :
		IBudget(startCash),
		baseCapacity(baseCapacity),
		workforceCapacity(workforceCapacity),
		payoutPercent(payoutPercent)
	{

	};
	void AddWorker(std::shared_ptr<Pop> worker);
	virtual void Payout();

	double GetCapacity()const;

	virtual void Produce() = 0;
};

#endif // SOURCE_H
