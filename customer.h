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
        void returnMovie(Movie &); // performs return for customer, records transaction in history
        void printInventoryHistory(); // prints customer’s history of movie inventory to console

    private:
        int id;
        string custFirst;
        string custLast;
        vector<Movie> currentMovies;
        vector<string> transactionHistory;
    
};


#endif // CUSTOMER_H
