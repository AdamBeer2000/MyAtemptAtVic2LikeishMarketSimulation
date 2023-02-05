#pragma once
enum PopType
{
	craftman, laborel, capitalist, farmer, aristocrat, artisan, clerk
};

class IPopType
{
protected:
	PopType myPopType;
public:

	IPopType(PopType myPopType) :myPopType(myPopType)
	{

	}
	PopType getPopType()const
	{
		return myPopType;
	}
};