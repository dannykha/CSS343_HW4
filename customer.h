// ----------------------------------------------------------------
// customer.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for customer.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - has associations to Store class to implement storage of
//   customers and movie inventory
// ----------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma once
#include <iostream>
#include <vector>
//#include "movie.h"
#include "classic.h"
#include "movieinventory.h"

using namespace std;

class Customer
{
    public:

        Customer(int, string, string); // id, firstname, lastname
        ~Customer();
        //setter functions
        void setName(string, string); //first and last name
        void setName(string); //full name
        void setID(int);
        
        //getter functions
        string getName(); //getter function to return name
        int getID();

        void printCurrInventory(); //print current inventory

        void addMovie(Movie &); // adds movie 

        // performs borrow for customer, records transaction in history
        void borrowMovie(Movie &);
        void borrowMovie(Classic &);

        // performs return for customer, records transaction in history
        void returnMovie(Movie &);
        void returnMovie(Classic &);

        // prints customer’s history of movie inventory to console
        void printInventoryHistory();

        friend ostream& operator << (ostream& out, Customer &rhs);
        bool operator == (Customer &);

    private:
        int id;
        string custFirst;
        string custLast;
        vector<Movie> currentMovies;
        vector<string> transactionHistory;
};

#endif // CUSTOMER_H
