// ----------------------------------------------------------------
// movieinventory.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for movieinventory.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - implements Movie and Classic classes to create a hashtable of
//   movie objects for record keeping
// ----------------------------------------------------------------

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

        //implemetns Movie objects for hashtable
        Movie *movie;

        //constructor with inital key and movie pair
        HashElement(int k, Movie *movi) {
            key = k;
            movie = movi;
        }
};

class MovieInventory
{
    public:
        //constructor
        MovieInventory();

        //destructor
        ~MovieInventory();

        //destructor helper function
        void destroy();

        //returns hash value of key
        int hashFunction(int key);

        //insert functions
        void insert(Movie *moviPtr);
        void insert(Classic *); //Classic has special parameters

        //search and remove functions
        Movie *search(int key);
        void remove(int key);

        //prints to console
        void printInventory();

        // void sortMovies();
        // bool compareGenre(Movie, Movie);
        // bool compareTitle(Movie, Movie);
        // bool compareComedyYear(Movie, Movie);
        // bool compareDramaDirector(Movie, Movie);
        // bool compareClassicRelease(Classic, Classic);
        // bool compareClassicActor(Classic, Classic);
    private:
        HashElement **table;
        vector<Movie> vecMovie;
        int numComedy, numDrama, numClassic;
};

#endif // MOVIEINVENTORY