#pragma once
enum PopType
{
	craftman, laborel, capitalist, farmer, aristocrat
};

class IPopType
{
protected:
	PopType myPopType;
public:

	IPopType(PopType myPopType) :myPopType(myPopType)
	{

	}
	PopType getProductType()const
	{
		return myPopType;
	}
};