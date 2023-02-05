#ifndef IPRODUCTTYPE_H
#define IPRODUCTTYPE_H

enum ProductType
{
	//rgo resources
	grain, wine, timber, cattle, fruit, fish, wool, coal, iron, cotton, tea, coffee, tropical_wood, tobaco, sulphur, silk, opium, precious_metal, rubber,
	//products
	aeroplane, ammunition, artillery, automobile, tanks, canned_food, cement, clipper, electric_gear, explosives, fabric, fertilizer, fuel, furniture, glass,
	liquor, lumber, luxury_clothes, luxury_furniture, machine_parts, paper, radio, regular_clothes, small_arms, steamer, steel, telephone,
	//both
	oil, dye
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
