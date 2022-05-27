#include "movie.h"
#include <iostream>
#include <fstream>

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

bool Movie::operator!=(Movie &movie)
{
    return !(*this == movie);
};