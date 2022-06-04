#ifndef MOVIEINVENTORY_H
#define MOVIEINVENTORY_H
#pragma once
#define TABLE_SIZE 250
#include "movie.h"

using namespace std;

class HashElement
{
    public:
        int key;
        Movie *movie;
        HashElement(int k, Movie *movi) {
            key = k;
            movie = movi;
        }
};

class MovieInventory
{
    public:
        MovieInventory();
        ~MovieInvetory();
        void destroy();
        int hashFunction(string key);
        void insert(Movie *moviPtr);
        Movie *search(int key);
        void remove(int key);
    private:
        HashElement **table;
};


#endif // MOVIEINVENTORY