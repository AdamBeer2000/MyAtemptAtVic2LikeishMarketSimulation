#ifndef SOURCE_H
#define SOURCE_H

class ISource
{

private:

protected:
	double myCapacity;

public:
	ISource(double capacity) :myCapacity(capacity)
	{

	};

	virtual void Produce(double ammount) = 0;
	virtual void Produce() = 0;
};

#endif // SOURCE_H
