#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma once;
#include <iostream>

using namespace std;

class Customer
{
    public:
        //setter functions
        bool setName(string, string);
        bool setName(string);
        bool setID(int);
        bool processCommands(string);
        string getName();

        int inventory(string); //return current inventory

        void addAction(); // adds actions to customer’s transaction queue
        void addMovie(); // adds movie 
        void borrowMovie(); // performs borrow for customer, records transaction in history
        void returnMovie(); // performs return for customer, records transaction in history
        void printInventoryHistory(); // prints customer’s history of movie inventory to console
        void printActionHistory(); // prints customer’s history of transactions to console
        void clearInventoryHistory(); // clears the customer’s history of movie inventory 
        void clearActionHistory(); // clears the customer’s history of transactions



    private:
        int id;
        string custFirst;
        string custLast;
    
};


#endif // CUSTOMER_H
