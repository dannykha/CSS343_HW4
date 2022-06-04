#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#pragma once;
#include <iostream>
#include "hashtable.h"
#include <fstream>

using namespace std;

class CustomerDatabase : public HashTable
{
    public:
        CustomerDatabase();
        ~CustomerDatabase();


    private:


};


#endif // CUSTOMERDATABASE_H