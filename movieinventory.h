// ----------------------------------------------------------------
// movieinventory.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for movieinventory.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - implements Customer class to create a hashtable of Movies
//   objects for record keeping
// ----------------------------------------------------------------

#ifndef HASTABLE_H
#define HASTABLE_H
#pragma once
#define TABLE_SIZE 250
#include "movie.h"
#include "classic.h"

using namespace std;

class HashElementMovie
{
    public:
        int key;
        
        //implements customer objects for hashtable
        Movie *movie;
        Classic *classic;
        bool isClassic;
        

        //default constructor
        HashElementMovie()
        {
            Movie temp = Movie();
	        Movie* tempPtr = &temp;
            key = 0;
            movie = tempPtr;
            isClassic = false;
        }

        //constuctor with inital key and customer pair
        HashElementMovie(int k, Movie *movi)
        {
            key = k;
            movie = movi;
            isClassic = false;
        }

        HashElementMovie(int k, Classic *classics)
        {
            key = k;
            classic = classics;
            isClassic = true;
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

        //returns hashvalue of key
        int hashFunction(int key);

        //search for, insert, and remove customers from
        //from database
        void insert(int key, Movie* moviePtr);
        void insert(int key, Classic* classicPtr);
        Movie* search(int key);
        Classic* classicSearch(int key);
        void remove(int key);

        void printInventory();

    private:
        HashElementMovie table[TABLE_SIZE];
};

#endif // HASTABLE_H