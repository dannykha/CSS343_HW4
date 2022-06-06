// ----------------------------------------------------------------
// comedy.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - develops Comedy class to initialize each comedy movie
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "comedy.h"
#include "borrow.h"
#include "return.h"
#include <iostream>

//constructor
Comedy::Comedy(const int stock, const string director, 
const string title, const int year)
{
    Movie::setStock(stock);
    Movie::setDirector(director);
    Movie::setTitle(title);
    Movie::setReleaseYear(year);
    Movie::setGenre("F");
};

//-----------------------------------------------------------------
//destructor
Comedy::~Comedy() {};