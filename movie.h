#ifndef MOVIE_H
#define MOVIE_H
#pragma once;
#include <iostream>
#include <fstream>


using namespace std;

class Movie
{
    public:
    
    bool operator == (Movie &);
    bool operator != (Movie &);

    

    private:
        string filmCategory;
        int stock;
        string director;
        string title;
        int year;
};


#endif // MOVIE_H