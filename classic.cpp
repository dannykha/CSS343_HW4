// ----------------------------------------------------------------
// classic.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - develops Classic class to initialize each classic movie
// and to return privatized values for ease of access
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "classic.h"
#include <iostream>

//constructor
Classic::Classic(const int tStock, const string director,
const string title, const string actorFirst, const string actorLast,
const int month, const int year)
{
    this->totalStock = tStock;
    Movie::setDirector(director);
    Movie::setTitle(title);
    this->actorFirst = actorFirst;
    this->actorLast = actorLast;
    this->month = month;
    Movie::setReleaseYear(year);
    Movie::setGenre("C");
};

//-----------------------------------------------------------------
//destructor
Classic::~Classic() {};

//-----------------------------------------------------------------
//actor getter-function; returns actor full name
string Classic::getActor()
{
    return (actorFirst + " " + actorLast);
};

//-----------------------------------------------------------------
//release date getter-function; returns month year
string Classic::getReleaseDate()
{
    return (month + " " + getReleaseYear());
};