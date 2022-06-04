#ifndef CLASSIC_H
#define CLASSIC_H
#pragma once
#include <iostream>
#include "movie.h"

using namespace std;

class Classic : public Movie
{
    public:
        //constructor
        Classic(const int tStock, const string director,
        const string title, const string actorFirst, const string actorLast,
        const int month, const int year);
        
        //destructor
        virtual ~Classic();

        //getter functions
        string getActor(); //return actor name
        string getReleaseDate(); //return release date

    private:
        string actorFirst;
        string actorLast;
        int month;
        int totalStock;
};

#endif // CLASSIC_H