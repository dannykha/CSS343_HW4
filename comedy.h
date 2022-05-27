#ifndef COMEDY_H
#define COMEDY_H
#pragma once;
#include <iostream>
#include "movie.h"

class Comedy : public Movie
{
    public:
        //constructor
        Comedy(const int stock, const string director, 
        const string title, const int year);
        
        //destructor
        virtual ~Comedy();

        //overloaded borrow and return functions
        int borrowMovie();
        int returnMovie();
};

#endif // COMEDY_H