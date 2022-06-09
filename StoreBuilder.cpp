// ----------------------------------------------------------------
// StoreBuilder.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 8, 2022
// ----------------------------------------------------------------
// Purpose - develops StoreBuilder class to initilaize the store
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "StoreBuilder.h"

//constructor
StoreBuilder::StoreBuilder() {}

//-----------------------------------------------------------------
//destructor
StoreBuilder::~StoreBuilder()
{
    for(auto i : storeList)
    {
        delete i;
    }
}

//-----------------------------------------------------------------
//add store function
void StoreBuilder::addStore(string &name)
{
    storeList.push_back(new Store(name));
}

//-----------------------------------------------------------------
//store list getter function
Store* StoreBuilder::getStore(int storeID)
{
    return storeList.at(storeID);
}