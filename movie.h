#ifndef MOVIE_H
#define MOVIE_H
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
};


#endif // MOVIE_H