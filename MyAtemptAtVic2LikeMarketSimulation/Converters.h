#include <string>
#include "IProductType.h"
#include "PopType.h"
#pragma once
static std::string ProductType2String(ProductType type)
{
	const std::string convert[] =
	{
		"grain","wine", "timber", "cattle", "fruit", "fish", "wool", "coal","iron", "cotton", "tea", "coffee", "tropical_wood", "tobaco",
		"sulphur", "silk", "opium", "precious_metal", "rubber",
		"aeroplane", "ammunition", "artillery", "automobile", "tanks", "canned_food", "cement", "clipper", "electric_gear", "explosives",
		"fabric", "fertilizer", "fuel", "furniture", "glass",
		"liquor", "lumber", "luxury_clothes", "luxury_furniture", "machine_parts", "paper", "radio", "regular_clothes", "small_arms",
		"steamer", "steel", "telephone",
		"oil", "dye"
	};

	return convert[type];
}


static std::string PopType2String(PopType type)
{
	const std::string convert[] =
	{
		"craftman", "laborel", "capitalist", "farmer", "aristocrat", "artisan"
	};

	return convert[type];
}

static const std::vector<ProductType> GetAllProductType()
{
	const std::vector<ProductType> types =
	{
		//rgo resources
		grain, wine, timber, cattle, fruit, fish, wool, coal, iron, cotton, tea, coffee, tropical_wood, tobaco, sulphur, silk, opium, precious_metal, rubber,
		//products
		aeroplane, ammunition, artillery, automobile, tanks, canned_food, cement, clipper, electric_gear, explosives, fabric, fertilizer, fuel, furniture, glass,
		liquor, lumber, luxury_clothes, luxury_furniture, machine_parts, paper, radio, regular_clothes, small_arms, steamer, steel, telephone,
		//both
		oil, dye
	};
	return types;
}

static const std::vector<ProductType> GetAllRGO()
{
	const std::vector<ProductType> types =
	{
		//rgo resources
		grain, timber, cattle, fruit, fish, wool, coal, iron, cotton, tea, coffee, tropical_wood, tobaco, sulphur, silk, opium, precious_metal, rubber,
		//both
		oil, dye
	};
	return types;
}

static const std::vector<ProductType> GetAllArtisanProduct()
{
	const std::vector<ProductType> types =
	{
		//products
		aeroplane, ammunition, artillery, automobile, tanks, canned_food, cement, clipper, electric_gear, explosives, fabric, fertilizer, fuel, furniture, glass,
		liquor, lumber, luxury_clothes, luxury_furniture, machine_parts, paper, radio, regular_clothes, small_arms, steamer, steel, telephone,wine
	};
	return types;
}