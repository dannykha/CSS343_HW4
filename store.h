#ifndef STORE_H
#pragma once;
#include <iostream>
#include <fstream>

using namespace std;

class Store
{
    public:
    void readInventory(ifstream &);
    void readCommands(ifstream &);
    void readCustomers(ifstream &);

    private:


};


#endif // STORE_H