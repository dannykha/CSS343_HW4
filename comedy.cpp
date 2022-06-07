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
#include <iostream>

//constructor
Comedy::Comedy(const int stock, const string director, 
const string title, const int year)
{
    setStock(stock);
    setDirector(director);
    setTitle(title);
    setReleaseYear(year);
    setGenre("F");
};

//-----------------------------------------------------------------
//destructor
Comedy::~Comedy() {};