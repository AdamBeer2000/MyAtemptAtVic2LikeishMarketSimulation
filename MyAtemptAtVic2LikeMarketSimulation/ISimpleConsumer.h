#pragma once
#include "IConsumer.h"

class ISimpleConsumer : public IConsumer
{
protected:
	std::map<ProductType, std::shared_ptr<Need>>needs;
public:

	ISimpleConsumer();

	void Consume(ProductType type, double ammount) override;
	void Restock(ProductType type, double ammount) override;

	virtual std::vector<ProductType>GetNeedTypes() = 0;
	virtual void AddNeed(Need n) = 0;
};
