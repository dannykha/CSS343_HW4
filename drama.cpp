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