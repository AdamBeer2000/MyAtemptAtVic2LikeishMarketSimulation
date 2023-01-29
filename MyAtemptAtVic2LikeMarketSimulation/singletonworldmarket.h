#ifndef SINGLETONWORLDMARKET_H
#define SINGLETONWORLDMARKET_H
#include "market.h";

class SingletonWorldMarket
{
	static Market* instance;

public:
	SingletonWorldMarket();
	static Market* getInstance();
};

#endif // SINGLETONWORLDMARKET_H
