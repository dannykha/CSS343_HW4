#include "customer.h"
#include <iostream>
#include <vector>

//FOR ANDREW
//name setter function
bool Customer::setName(string first, string last)
{
    this->custFirst = first;
    this->custLast = last;
};

//-----------------------------------------------------------------
//name setter function
bool Customer::setName(string)
{

};

//-----------------------------------------------------------------
//ID number setter function
bool Customer::setID(int number)
{
    this->id = number;
};

//-----------------------------------------------------------------
//
bool Customer::processCommands(string)
{

};

//-----------------------------------------------------------------
//
string Customer::getName()
{
    return custFirst + " " + custLast;
};

//-----------------------------------------------------------------
//return current inventory
int Customer::inventory(string)
{
    vector<Movie> currentMovies;
    currentMovies.push_back()
};

//-----------------------------------------------------------------
//adds actions to customer’s transaction queue
void Customer::addAction()
{

};

//-----------------------------------------------------------------
//adds movie 
void Customer::addMovie()
{

};

//-----------------------------------------------------------------
//borrow function; stock - 1
void Customer::borrowMovie()
{

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