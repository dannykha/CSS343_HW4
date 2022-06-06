// ----------------------------------------------------------------
// drama.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - develops Drama class to initialize each drama movie
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "drama.h"
#include <iostream>

//constructor
Drama::Drama(const int stock, const string director, 
const string title, const int year)
{
    Movie::setStock(stock);
    Movie::setDirector(director);
    Movie::setTitle(title);
    Movie::setReleaseYear(year);
    Movie::setGenre("D");
};

//-----------------------------------------------------------------
//destructor
Drama::~Drama() {};