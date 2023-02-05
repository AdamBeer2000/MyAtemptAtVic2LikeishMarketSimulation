#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <memory>
#include "IProductType.h"
#include "IBudget.h"

class ISource;

class ProductStorage
{
private:
	ProductType myType;
	double amount;
	IBudget* mySource;
public:

	ProductStorage(ProductType pType, double amount, IBudget* pSource);
	double getAmount() const;
	void increaseBy(double amount);
	void decreaseBy(double amount);
	ProductType getType() const;
	IBudget* getSource() const;
	void MergerInto(ProductStorage& other);
};

inline bool operator == (const ProductStorage& a, const ProductStorage& b)
{
	return a.getSource() == b.getSource();
}
#endif // PRODUCT_H
