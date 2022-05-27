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

//-----------------------------------------------------------------
//borrow function; stock - 1
int Comedy::borrowMovie()
{
    
};

//-----------------------------------------------------------------
//return function; stock + 1
int Comedy::returnMovie()
{

};