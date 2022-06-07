// ----------------------------------------------------------------
// drama.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for drama.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - inherits from Movie class
// ----------------------------------------------------------------

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
        ~Drama();
};
#endif // DRAMA_H