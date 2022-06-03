#ifndef STORE_H
#define STORE_H
#pragma once;
#include <iostream>
#include <fstream>
#include "inventory.h"

using namespace std;

class Store
{
    public:
        Store();
        ~Store();
        void readMovies(string &);
        void readCommands(string &);
        void readCustomers(string &);

    private:


};


#endif // STORE_H