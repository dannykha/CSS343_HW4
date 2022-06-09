// ----------------------------------------------------------------
// StoreBuilder.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 8, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for StoreBuilder.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#ifndef STOREBUILDER_H
#define STOREBUILDER_H
#pragma once
#include <vector>
#include "store.h"

using namespace std;

class StoreBuilder 
{
    public:
        //constructor
        StoreBuilder();

        //destructor
        ~StoreBuilder();

        //initialize store
        void addStore(string &);

        //getter function
        Store* getStore(int);

    private:
        vector<Store*> storeList;
};

#endif // STOREBUILDER_H