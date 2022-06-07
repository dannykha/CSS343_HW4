// ----------------------------------------------------------------
// movie.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - develops Movie class to initialize each movie
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "movie.h"
#include <iostream>
#include <fstream>

//-----------------------------------------------------------------
//overloaded == operator
bool Movie::operator==(Movie &movie)
{
    if (this->filmCategory != movie.filmCategory ||
    this->title != movie.title || 
    this->director != movie.director || this->year != movie.year)
    {
        return false;
    };

    return true;
};

//-----------------------------------------------------------------
//overloaded != operator, uses overloaded == for simplicity
bool Movie::operator!=(Movie &movie)
{
    return !(*this == movie);
};

//-----------------------------------------------------------------
//stock getter-function; returns stock of movie
int Movie::getStock()
{
    return stock;
};

//-----------------------------------------------------------------
//title getter-function; returns title of movie
string Movie::getTitle()
{
    return title;
};

//-----------------------------------------------------------------
//director getter-function; returns director of movie
string Movie::getDirector()
{
    return director;
};

//-----------------------------------------------------------------
//release year getter-function; returns release year of movie
int Movie::getReleaseYear()
{
    return year;
};

//-----------------------------------------------------------------
//genre getter-function; returns genre of movie
string Movie::getGenre()
{
    return filmCategory;
};

//-----------------------------------------------------------------
//stock setter-function; returns stock of movie
void Movie::setStock(const int stock)
{
    this->stock = stock;
};

//-----------------------------------------------------------------
//title setter-function; returns title of movie
void Movie::setTitle(const string title)
{
    this->title = title;
};

//-----------------------------------------------------------------
//director setter-function; returns director of movie
void Movie::setDirector(const string director)
{
    this->director = director;
};

//-----------------------------------------------------------------
//release year setter-function; returns release year of movie
void Movie::setReleaseYear(const int year)
{
    this->year = year;
};

//-----------------------------------------------------------------
//genre setter-function; returns genre of movie
void Movie::setGenre(const string genre)
{
    this->filmCategory = genre;
};
