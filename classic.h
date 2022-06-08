// ----------------------------------------------------------------
// classic.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for classic.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - inherits from Movie class
// - has months for full release date
// - has major actors' name
// - has total stock of all movie instances
// ----------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H
#pragma once
#include <iostream>
#include "movie.h"

using namespace std;

class Classic : public Movie
{
    public:

        Classic();
        //constructor
        Classic(const int tStock, const string director,
        const string title, const string actorFirst, const string actorLast,
        const int month, const int year);
        
        //destructor
        ~Classic();

        //getter functions
        string getActor(); //return actor name
        string getReleaseDate(); //return release date
        int getTotalStock();

    private:
        string actorFirst;
        string actorLast;
        int month;
        int totalStock;
};

#endif // CLASSIC_H