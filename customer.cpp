#include "customer.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//FOR ANDREW
//name setter function
bool Customer::setName(string first, string last)
{
    this->custFirst = first;
    this->custLast = last;
};

//-----------------------------------------------------------------
//name setter function
bool Customer::setName(string name)
{
    std::stringstream s(name);
    s>>custFirst>>custLast;
};

//-----------------------------------------------------------------
//ID number setter function
bool Customer::setID(int number)
{
    this->id = number;
};


//-----------------------------------------------------------------
//
string Customer::getName()
{
    return custFirst + " " + custLast;
};

//-----------------------------------------------------------------
//print current inventory
void Customer::printCurrInventory()
{
    for (auto i = currentMovies.begin(); i != currentMovies.end(); i++)
    {
        cout << *i << endl;
    }
    
};


//-----------------------------------------------------------------
//adds movie 
void Customer::addMovie(Movie &movie)
{
    currentMovies.push_back(movie);
};

//-----------------------------------------------------------------
//borrow function; stock - 1
void Customer::borrowMovie(Movie &movie)
{
    addMovie(movie);
    
};

//-----------------------------------------------------------------
//return function; stock + 1
void Customer::returnMovie()
{
    
};

//-----------------------------------------------------------------
//prints customer’s history of movie inventory to console
void Customer::printInventoryHistory()
{

};

//-----------------------------------------------------------------
//prints customer’s history of transactions to console
void Customer::printActionHistory()
{

};

//-----------------------------------------------------------------
//clears the customer’s history of movie inventory 
void Customer::clearInventoryHistory()
{

};

//-----------------------------------------------------------------
//clears the customer’s history of transactions
void Customer::clearActionHistory()
{

};