#ifndef MOVIE_H
#define MOVIE_H
#pragma once;
#include <iostream>
#include <fstream>


using namespace std;

class Movie
{
    public:
        //default constructor to be overloaded by each genre class
        Movie();
        //destructor
        virtual ~Movie();

        //overloaded comparison operators
        bool operator==(Movie &);
        bool operator!=(Movie &);

        //getter functions
        virtual int getStock(); //return movie stock
        virtual string getTitle(); //return movie title
        virtual string getDirector(); //return movie director
        virtual int getReleaseYear(); //return movie release year
        virtual string getGenre(); //return movie genre

        //setter functions
        virtual void setStock(const int stock); //set movie stock
        virtual void setTitle(const string title); //set movie title
        virtual void setDirector(const string director); //set movie director
        virtual void setReleaseYear(const int year); //set movie release year
        virtual void setGenre(const string genre); //set movie genre
    

    private:
        string filmCategory;
        int stock;
        string director;
        string title;
        int year;
};


#endif // MOVIE_H