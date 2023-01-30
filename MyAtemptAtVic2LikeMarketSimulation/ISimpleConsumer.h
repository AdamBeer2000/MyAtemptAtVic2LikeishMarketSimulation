#pragma once
#include "IConsumer.h"

class ISimpleConsumer : public IConsumer
{
protected:
	std::map<ProductType, std::shared_ptr<Need>>needs;
public:

	ISimpleConsumer();
	ISimpleConsumer(std::map<ProductType, std::shared_ptr<Need>>needs);

	void Consume(ProductType type, double ammount) override;
	void Restock(ProductType type, double ammount) override;
	void Restock() override;
	void Consume() override;
	std::vector<ProductType>GetNeedTypes() override;
	void AddNeed(Need n) override;
};
