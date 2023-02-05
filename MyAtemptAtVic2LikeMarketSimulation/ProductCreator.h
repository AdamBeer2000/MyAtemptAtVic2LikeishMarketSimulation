#pragma once
#include "Aristocrat.h"
#include <functional>

class ProductCreator
{
	ProductType EndProductType;
	double endProductAmmount;
public:
	class ProduceNeed
	{
	public:
		ProductType neededProduct;
		const double neededAmmount;
		double storedAmmount;

		ProduceNeed(ProductType neededProduct, const double neededAmmount, double storedAmmount = 0)
			:neededProduct(neededProduct), neededAmmount(neededAmmount), storedAmmount(storedAmmount) {}

		double NeededToCreateAmmount(double ammount)const
		{
			return neededAmmount * ammount;
		}

		double Defficit(double ammount)const
		{
			return ammount * neededAmmount - storedAmmount;
		}

		double NeedFullfiled(double ammount)const
		{
			return storedAmmount / (neededAmmount * ammount);
		}

		void AddAmount(double ammount)
		{
			storedAmmount += ammount;
		}

		void SubAmmount(double ammount)
		{
			storedAmmount -= ammount;
		}

		void Use(double ammount)
		{
			storedAmmount -= ammount * neededAmmount;
		}

		double CanMake()
		{
			return storedAmmount / neededAmmount;
		}

		bool operator < (const ProduceNeed& other) const
		{
			return other.NeededToCreateAmmount(1) < NeededToCreateAmmount(1);
		}
	};

	std::vector<std::shared_ptr<ProduceNeed>>needs = std::vector<std::shared_ptr<ProduceNeed>>();
public:

	ProductCreator(ProductType EndProductType, double endProductAmmount)
		:EndProductType(EndProductType), endProductAmmount(endProductAmmount)
	{

	}
	ProductCreator(ProductType EndProductType, double endProductAmmount, std::vector<std::shared_ptr<ProduceNeed>>needs)
		:EndProductType(EndProductType), needs(needs), endProductAmmount(endProductAmmount)
	{

	}

	double Produce(IBudget* creator, double ammount)
	{
		std::sort(needs.begin(), needs.end(),
			[ammount](std::shared_ptr<ProduceNeed> a, std::shared_ptr<ProduceNeed> b)
			{
				return a.get()->Defficit(ammount) > b.get()->Defficit(ammount);
			});


		for (auto n : needs)
		{
			auto deficit = n.get()->Defficit(ammount);
			SingletonWorldMarket::getInstance()->BuyAmount(n.get()->neededProduct, deficit, nullptr, creator);
			n.get()->AddAmount(deficit);
		}

		std::shared_ptr<ProduceNeed>need = *std::min_element(needs.begin(), needs.end(),
			[ammount](std::shared_ptr<ProduceNeed> a, std::shared_ptr<ProduceNeed> b)
			{
				return a.get()->CanMake() < b.get()->CanMake();
			});

		double canMake = need.get()->CanMake();

		if (canMake > ammount)
			canMake = ammount;

		for (auto n : needs)
		{
			n->Use(canMake);
		}

		if (canMake > 0)
			SingletonWorldMarket::getInstance()->AddToMarket(ProductStorage(EndProductType, canMake, creator));

		return ammount;
	}

	double Produce(IBudget* creator, int FactorySizeBase, double Throughput, double OutputEfficiency, double InputEfficiency)
	{
		auto market = SingletonWorldMarket::getInstance();
		for (auto& need : needs)
		{
			double input = FactorySizeBase * (need.get()->neededAmmount) * Throughput * InputEfficiency;
			market->BuyAmount(need.get()->neededProduct, input, nullptr, creator);
			need.get()->AddAmount(input);
		}

		double output = FactorySizeBase * endProductAmmount * Throughput * OutputEfficiency;

		std::shared_ptr<ProduceNeed>leastFullfiled = *std::min_element(needs.begin(), needs.end(),
			[output](std::shared_ptr<ProduceNeed> a, std::shared_ptr<ProduceNeed> b)
			{
				return a.get()->NeedFullfiled(output) < b.get()->NeedFullfiled(output);
			});

		output *= leastFullfiled.get()->NeedFullfiled(output);


		for (auto n : needs)
		{
			n->Use(output);
		}
		SingletonWorldMarket::getInstance()->AddToMarket(ProductStorage(EndProductType, output, creator));

		return output;
	}

	void AddNeed(ProductType neededProduct, const double neededAmmount)
	{
		needs.push_back(std::make_shared<ProduceNeed>(neededProduct, neededAmmount / endProductAmmount, 0));
	}

	static ProductCreator* GetCreatorForArtisan(ProductType type)
	{
		ProductCreator* creator = nullptr;

		switch (type)
		{
		case grain:
			break;
		case wine:
			creator = new ProductCreator(telephone, 7);
			creator->AddNeed(fruit, 10);
			creator->AddNeed(glass, 10);
			break;
		case timber:
			break;
		case cattle:
			break;
		case fruit:
			break;
		case fish:
			break;
		case wool:
			break;
		case coal:
			break;
		case iron:
			break;
		case cotton:
			break;
		case tea:
			break;
		case coffee:
			break;
		case tropical_wood:
			break;
		case tobaco:
			break;
		case sulphur:
			break;
		case silk:
			break;
		case opium:
			break;
		case precious_metal:
			break;
		case rubber:
			break;
		case aeroplane:
			creator = new ProductCreator(tanks, 1);
			creator->AddNeed(rubber, 1);
			creator->AddNeed(electric_gear, 2);
			creator->AddNeed(lumber, 3.3);
			creator->AddNeed(machine_parts, 1.6);
			break;
		case ammunition:
			creator = new ProductCreator(ammunition, 3);
			creator->AddNeed(coal, 2);
			creator->AddNeed(sulphur, 2);
			creator->AddNeed(iron, 5);
			break;
		case artillery:
			creator = new ProductCreator(artillery, 1.3);
			creator->AddNeed(steel, 8);
			creator->AddNeed(explosives, 1);
			break;
		case automobile:
			creator = new ProductCreator(automobile, 1.42);
			creator->AddNeed(rubber, 1);
			creator->AddNeed(electric_gear, 1.5);
			creator->AddNeed(steel, 2.25);
			creator->AddNeed(rubber, 1);
			break;
		case tanks:
			creator = new ProductCreator(tanks, 1);
			creator->AddNeed(rubber, 1);
			creator->AddNeed(electric_gear, 1);
			creator->AddNeed(machine_parts, 0.8);
			creator->AddNeed(automobile, 0.3);
			break;
		case canned_food:
			creator = new ProductCreator(tanks, 6);
			creator->AddNeed(fish, 12);
			creator->AddNeed(cattle, 12);
			creator->AddNeed(grain, 12);
			creator->AddNeed(iron, 2);
			break;
		case cement:
			creator = new ProductCreator(cement, 3);
			creator->AddNeed(coal, 12);
			break;
		case clipper:
			creator = new ProductCreator(clipper, 10);
			creator->AddNeed(timber, 12);
			creator->AddNeed(fabric, 12);
			creator->AddNeed(steel, 12);
			break;
		case electric_gear:
			creator = new ProductCreator(electric_gear, 5);
			creator->AddNeed(rubber, 4);
			creator->AddNeed(coal, 5);
			creator->AddNeed(iron, 5);
			break;
		case explosives:
			creator = new ProductCreator(explosives, 3);
			creator->AddNeed(fertilizer, 4);
			creator->AddNeed(ammunition, 5);
			break;
		case fabric:
			creator = new ProductCreator(fabric, 45);
			creator->AddNeed(cotton, 18);
			creator->AddNeed(dye, 2);
			break;
		case fertilizer:
			creator = new ProductCreator(fertilizer, 5);
			creator->AddNeed(sulphur, 6);
			break;
		case fuel:
			creator = new ProductCreator(fuel, 2);
			creator->AddNeed(oil, 2.5);
			break;
		case furniture:
			creator = new ProductCreator(furniture, 12);
			creator->AddNeed(timber, 20);
			creator->AddNeed(lumber, 20);
			break;
		case glass:
			creator = new ProductCreator(glass, 18);
			creator->AddNeed(coal, 14);
			break;
		case liquor:
			creator = new ProductCreator(liquor, 10);
			creator->AddNeed(glass, 8);
			creator->AddNeed(glass, 10);
			break;
		case lumber:
			creator = new ProductCreator(lumber, 110);
			creator->AddNeed(timber, 100);
			break;
		case luxury_clothes:
			creator = new ProductCreator(luxury_clothes, 1);
			creator->AddNeed(regular_clothes, 0.9);
			creator->AddNeed(silk, 3.9);
			break;
		case luxury_furniture:
			creator = new ProductCreator(luxury_furniture, 1.1);
			creator->AddNeed(furniture, 2);
			creator->AddNeed(tropical_wood, 7.5);
			break;
		case machine_parts:
			creator = new ProductCreator(machine_parts, 2);
			creator->AddNeed(coal, 5);
			creator->AddNeed(steel, 9);
			break;
		case paper:
			creator = new ProductCreator(paper, 20);
			creator->AddNeed(timber, 50);
			break;
		case radio:
			creator = new ProductCreator(radio, 6.5);
			creator->AddNeed(electric_gear, 3);
			creator->AddNeed(glass, 10);
			break;
		case regular_clothes:
			creator = new ProductCreator(regular_clothes, 72);
			creator->AddNeed(fabric, 40);
			break;
		case small_arms:
			creator = new ProductCreator(small_arms, 2);
			creator->AddNeed(ammunition, 2);
			creator->AddNeed(steel, 3);
			break;
		case steamer:
			creator = new ProductCreator(steamer, 3);
			creator->AddNeed(coal, 20);
			creator->AddNeed(steel, 11);
			break;
		case steel:
			creator = new ProductCreator(steel, 20);
			creator->AddNeed(coal, 5);
			creator->AddNeed(iron, 20);
			break;
		case telephone:
			creator = new ProductCreator(telephone, 20);
			creator->AddNeed(electric_gear, 2.5);
			creator->AddNeed(glass, 15);
			break;
		case oil:
			break;
		case dye:
			break;
		default:
			break;
		}

		return creator;
	};

	static ProductCreator* GetCreatorForFactory(ProductType type)
	{
		ProductCreator* creator = nullptr;

		switch (type)
		{
		case grain:
			break;
		case wine:
			creator = new ProductCreator(telephone, 7);
			creator->AddNeed(fruit, 10);
			creator->AddNeed(glass, 10);
			break;
		case timber:
			break;
		case cattle:
			break;
		case fruit:
			break;
		case fish:
			break;
		case wool:
			break;
		case coal:
			break;
		case iron:
			break;
		case cotton:
			break;
		case tea:
			break;
		case coffee:
			break;
		case tropical_wood:
			break;
		case tobaco:
			break;
		case sulphur:
			break;
		case silk:
			break;
		case opium:
			break;
		case precious_metal:
			break;
		case rubber:
			break;
		case aeroplane:
			creator = new ProductCreator(tanks, 1);
			creator->AddNeed(rubber, 1);
			creator->AddNeed(electric_gear, 2);
			creator->AddNeed(lumber, 3.3);
			creator->AddNeed(machine_parts, 1.6);
			break;
		case ammunition:
			creator = new ProductCreator(ammunition, 3);
			creator->AddNeed(coal, 2);
			creator->AddNeed(sulphur, 2);
			creator->AddNeed(iron, 5);
			break;
		case artillery:
			creator = new ProductCreator(artillery, 1.3);
			creator->AddNeed(steel, 8);
			creator->AddNeed(explosives, 1);
			break;
		case automobile:
			creator = new ProductCreator(automobile, 1.42);
			creator->AddNeed(rubber, 1);
			creator->AddNeed(electric_gear, 1.5);
			creator->AddNeed(steel, 2.25);
			creator->AddNeed(rubber, 1);
			break;
		case tanks:
			creator = new ProductCreator(tanks, 1);
			creator->AddNeed(rubber, 1);
			creator->AddNeed(electric_gear, 1);
			creator->AddNeed(machine_parts, 0.8);
			creator->AddNeed(automobile, 0.3);
			break;
		case canned_food:
			creator = new ProductCreator(tanks, 6);
			creator->AddNeed(fish, 12);
			creator->AddNeed(cattle, 12);
			creator->AddNeed(grain, 12);
			creator->AddNeed(iron, 2);
			break;
		case cement:
			creator = new ProductCreator(cement, 3);
			creator->AddNeed(coal, 12);
			break;
		case clipper:
			creator = new ProductCreator(clipper, 10);
			creator->AddNeed(timber, 12);
			creator->AddNeed(fabric, 12);
			creator->AddNeed(steel, 12);
			break;
		case electric_gear:
			creator = new ProductCreator(electric_gear, 5);
			creator->AddNeed(rubber, 4);
			creator->AddNeed(coal, 5);
			creator->AddNeed(iron, 5);
			break;
		case explosives:
			creator = new ProductCreator(explosives, 3);
			creator->AddNeed(fertilizer, 4);
			creator->AddNeed(ammunition, 5);
			break;
		case fabric:
			creator = new ProductCreator(fabric, 45);
			creator->AddNeed(cotton, 18);
			creator->AddNeed(dye, 2);
			break;
		case fertilizer:
			creator = new ProductCreator(fertilizer, 5);
			creator->AddNeed(sulphur, 6);
			break;
		case fuel:
			creator = new ProductCreator(fuel, 2);
			creator->AddNeed(oil, 2.5);
			break;
		case furniture:
			creator = new ProductCreator(furniture, 12);
			creator->AddNeed(timber, 20);
			creator->AddNeed(lumber, 20);
			break;
		case glass:
			creator = new ProductCreator(glass, 18);
			creator->AddNeed(coal, 14);
			break;
		case liquor:
			creator = new ProductCreator(liquor, 10);
			creator->AddNeed(glass, 8);
			creator->AddNeed(glass, 10);
			break;
		case lumber:
			creator = new ProductCreator(lumber, 110);
			creator->AddNeed(timber, 100);
			break;
		case luxury_clothes:
			creator = new ProductCreator(luxury_clothes, 1);
			creator->AddNeed(regular_clothes, 0.9);
			creator->AddNeed(silk, 3.9);
			break;
		case luxury_furniture:
			creator = new ProductCreator(luxury_furniture, 1.1);
			creator->AddNeed(furniture, 2);
			creator->AddNeed(tropical_wood, 7.5);
			break;
		case machine_parts:
			creator = new ProductCreator(machine_parts, 2);
			creator->AddNeed(coal, 5);
			creator->AddNeed(steel, 9);
			break;
		case paper:
			creator = new ProductCreator(paper, 20);
			creator->AddNeed(timber, 50);
			break;
		case radio:
			creator = new ProductCreator(radio, 6.5);
			creator->AddNeed(electric_gear, 3);
			creator->AddNeed(glass, 10);
			break;
		case regular_clothes:
			creator = new ProductCreator(regular_clothes, 72);
			creator->AddNeed(fabric, 40);
			break;
		case small_arms:
			creator = new ProductCreator(small_arms, 2);
			creator->AddNeed(ammunition, 2);
			creator->AddNeed(steel, 3);
			break;
		case steamer:
			creator = new ProductCreator(steamer, 3);
			creator->AddNeed(coal, 20);
			creator->AddNeed(steel, 11);
			break;
		case steel:
			creator = new ProductCreator(steel, 20);
			creator->AddNeed(coal, 5);
			creator->AddNeed(iron, 20);
			break;
		case telephone:
			creator = new ProductCreator(telephone, 20);
			creator->AddNeed(electric_gear, 2.5);
			creator->AddNeed(glass, 15);
			break;
		case oil:
			break;
		case dye:
			break;
		default:
			break;
		}

		return creator;
	};
};
