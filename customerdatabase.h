// ----------------------------------------------------------------
// customerdatabase.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 8, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for customerdatabase.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - implements Customer class to create a hashtable of Customer
//   objects for record keeping
// ----------------------------------------------------------------

#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#pragma once
#define TABLE_SIZE 250
#include "customer.h"

using namespace std;

class HashElementCust
{
    public:
        int key;
        
        //implements customer objects for hashtable
        Customer *customer;
        
        //default constructor
        HashElementCust()
        {
            Customer temp = Customer(0, "first", "last");
	        Customer* tempPtr = &temp;
            key = 0;
            customer = tempPtr;
        }

        //constuctor with inital key and customer pair
        HashElementCust(int k, Customer *cust)
        {
            key = k;
            customer = cust;
        }
};

class CustomerDatabase
{
    public:
        //constructor
        CustomerDatabase();

        //destructor
        ~CustomerDatabase();

        //destructor helper function
        void destroy();

        //returns hashvalue of key
        int hashFunction(int key);

        //search for, insert, and remove customers from database
        void insert(int key, Customer *custPtr);
        Customer* search(int key);
        void remove(int key);

    private:
        HashElementCust table[TABLE_SIZE];
};

#endif // CUSTOMERDATABASE_H