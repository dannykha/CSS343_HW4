#ifndef MOVIEINVENTORY_H
#define MOVIEINVENTORY_H
#pragma once
#define TABLE_SIZE 250
#include "movie.h"
#include "classic.h"
#include <string>
#include <iostream> 
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class HashElement
{
    public:
        int key;
        Movie *movie;
        HashElement(int k, Movie *movi) {
            key = k;
            movie = movi;
        }
};

class MovieInventory
{
    public:
        MovieInventory();
        ~MovieInventory();
        void destroy();
        int hashFunction(int key);
        void insert(Movie *moviPtr);
        void insert(Classic *);
        Movie *search(int key);
        void remove(int key);
        void printInventory();
        void sortMovies();
        bool compareGenre(Movie, Movie);
        bool compareTitle(Movie, Movie);
        bool compareComedyYear(Movie, Movie);
        bool compareDramaDirector(Movie, Movie);
        bool compareClassicRelease(Classic, Classic);
        bool compareClassicActor(Classic, Classic);
    private:
        HashElement **table;
        vector<Movie> vecMovie;
        int numComedy, numDrama, numClassic;
};


#endif // MOVIEINVENTORY