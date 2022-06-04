#ifndef STOREBUILDER_H
#define STOREBUILDER_H
#pragma once
#include <vector>
#include "store.h"

using namespace std;

class StoreBuilder 
{
    public:
        StoreBuilder();
        ~StoreBuilder();
        void addStore(string &);
        Store getStore(int);

    private:
        vector<Store> storeList;

};

#endif // STOREBUILDER_H