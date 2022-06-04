#ifndef STORE_H
#define STORE_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "movieinventory.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "customerdatabase.h"

using namespace std;

class Store
{
    public:
        Store(string &);
        ~Store();
        void readMovies(string &);
        void readCommands(string &);
        void readCustomers(string &);

        void setStoreName(string &);
        MovieInventory StoreInventory;
    private:
        
        CustomerDatabase StoreCustomerDatabase;
        string storeName;

};


#endif // STORE_H