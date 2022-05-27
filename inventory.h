#ifndef INVENTORY_H
#define INVENTORY_H
#pragma once;
#include "movie.h"
#include "hashtable.h"

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory() {};
        bool executeInventory();
        virtual void addMovie();
        virtual void printInventory();
    private:
        HashTable inventory;
};
#endif // INVENTORY_H