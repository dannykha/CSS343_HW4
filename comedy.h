// ----------------------------------------------------------------
// comedy.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for comedy.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - inherits from Movie class
// ----------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H
#pragma once
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
};

#endif // COMEDY_H