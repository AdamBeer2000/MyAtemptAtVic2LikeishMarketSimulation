#ifndef IPRODUCTTYPE_H
#define IPRODUCTTYPE_H

enum ProductType
{
	beer, wheat, greap, wine
};

class IProductType
{
protected:
	ProductType myProductType;
public:

	IProductType(ProductType myProductType) :myProductType(myProductType)
	{

	}
	ProductType getProductType()const
	{
		return myProductType;
	}
};

#endif // PRODUCTTYPE_H
