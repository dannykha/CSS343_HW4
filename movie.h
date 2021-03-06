// ----------------------------------------------------------------
// movie.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 8, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for movie.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - is inherited by Comedy, Drama, and Classic classes
// - setters and getters for ease of access to private variables
// - overloaded comparison operators to ensure that movies are 
//   properly selected
// ----------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H
#pragma once
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
        friend ostream& operator<<(ostream& out, Movie&);

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