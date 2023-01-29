#include "singletonworldmarket.h"

Market * SingletonWorldMarket::instance=nullptr;

Market *SingletonWorldMarket::getInstance()
{
    if(!instance)
        instance = new Market();
    return instance;
}

SingletonWorldMarket::SingletonWorldMarket()
{

}
