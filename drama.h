#ifndef DRAMA_H
#define DRAMA_H
#pragma once
#include <iostream>
#include "movie.h"

class Drama : public Movie
{
    public:
        //constructor
        Drama(const int stock, const string director, 
        const string title, const int year);
        
        //destructor
        virtual ~Drama();
};
#endif // DRAMA_H