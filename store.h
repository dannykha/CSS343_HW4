// ----------------------------------------------------------------
// store.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - provide declarations for store.cpp file
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - implements MovieInventory, Comedy, Drama, and Classic classes
//   to create store inventory
// - movies, customers, and customer commands are initiliazed here
// ----------------------------------------------------------------

#ifndef STORE_H
#define STORE_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "movieinventory.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "customerdatabase.h"

using namespace std;

class Store
{
    public:
        //constructor
        Store();
        //constructor with inital store name
        Store(string &);

        //destructor
        ~Store();

        //reader functions
        void readMovies(string &);
        void readCommands(string &);
        void readCustomers(string &);
        
        //setter function
        void setStoreName(string &);

        string getStoreName();
        
        //implements MovieInventory to keep track of
        //all movies held in store
        static MovieInventory StoreInventory;
        string ltrim(const string &);
        string rtrim(const string &);
        string trim(const string &);
    private:
        const string WHITESPACE = " \n\r\t\f\v";
        CustomerDatabase StoreCustomerDatabase;
        string storeName;
};


#endif // STORE_H