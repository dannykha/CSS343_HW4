#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#pragma once
#include "HashTable.h"
#include <iostream>
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