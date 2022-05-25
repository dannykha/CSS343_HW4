#ifndef INVENTORY_H
#define INVENTORY_H
#pragma once;
#include "movie.h"
#include "hashtable.h"

class Inventory
{
    public:
        bool executeInventory(Movie &);
        bool addMovie(Movie *);
        void printInventory();
    private:
        HashTable inventory;
};
#endif // INVENTORY_H