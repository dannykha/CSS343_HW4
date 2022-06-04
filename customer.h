#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma once
#include <iostream>
#include "movie.h"
#include "movieinventory.h"
#include "store.h"

using namespace std;

class Customer
{
    public:

        Customer(int, string, string); // id, firstname, lastname
        bool setName(string, string);
        bool setName(string);
        bool setID(int);

        string getName();

        void printCurrInventory(); //print current inventory

        void addMovie(Movie &); // adds movie 
        void borrowMovie(Movie &); // performs borrow for customer, records transaction in history
        void returnMovie(); // performs return for customer, records transaction in history
        void printInventoryHistory(); // prints customer’s history of movie inventory to console
        void printActionHistory(); // prints customer’s history of transactions to console
        void clearInventoryHistory(); // clears the customer’s history of movie inventory 
        void clearActionHistory(); // clears the customer’s history of transactions



    private:
        int id;
        string custFirst;
        string custLast;
        vector<Movie> currentMovies;
    
};


#endif // CUSTOMER_H
