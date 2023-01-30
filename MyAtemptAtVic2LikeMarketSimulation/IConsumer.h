#pragma once
#include <map>
#include <memory>
#include <vector>
#include "need.h"

class IConsumer
{
private:

protected:
	virtual void Consume(ProductType type, double ammount) = 0;
	virtual void Restock(ProductType type, double ammount) = 0;
	virtual void Restock() = 0;
	virtual void Consume() = 0;
public:
	virtual std::vector<ProductType>GetNeedTypes() = 0;
	virtual void AddNeed(Need n) = 0;
};