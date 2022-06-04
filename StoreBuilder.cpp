#include "storebuilder.h"

void StoreBuilder::addStore(string &name)
{
    storeList.push_back(Store(name));
}

Store StoreBuilder::getStore(int storeID)
{
    return storeList.at(storeID);
}