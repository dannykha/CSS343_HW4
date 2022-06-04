#include "customer.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

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
    string temp = movie.getGenre() + movie.getDirector() + to_string(movie.getReleaseYear()) + movie.getTitle();
	int key = stoi(temp);
    StoreInventory.search(key).setStock(StoreInventory.search(key).getStock() - 1);
    string message = "User borrowed: " + movie.getReleaseYear() + movie.getTitle(); 
    transactionHistory.push_back(message);
};

//-----------------------------------------------------------------
//return function; stock + 1
void Customer::returnMovie(Movie &movie)
{
    for (int i = 0; i <= currentMovies.size(); i++)
    {
        if (currentMovies.at(i) == movie)
        {
            vector<Movie>::iterator it;
            it = currentMovies.begin() + i; // might need to be i - 1
            currentMovies.erase(it);
        }
    }
    string temp = movie.getGenre() + movie.getDirector() + to_string(movie.getReleaseYear()) + movie.getTitle();
	int key = stoi(temp);
    StoreInventory.search(key).setStock(StoreInventory.search(key).getStock() + 1);

    string message = "User returned: " + movie.getReleaseYear() + movie.getTitle(); 
    transactionHistory.push_back(message);    
};

//-----------------------------------------------------------------
//prints customer’s history of movie inventory to console
void Customer::printInventoryHistory()
{
    for (auto i = 0; i <= transactionHistory.size(); i++)
    {
        int it = (int) i;
        cout << transactionHistory.at(it) << endl;
    }
};
