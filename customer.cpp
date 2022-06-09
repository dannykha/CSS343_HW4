// ----------------------------------------------------------------
// customer.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - develops Customer class to initialize each customer
// and perform borrow and return as commanded by each customer
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - movies and resulting customer transactions are stored in
//   Store class
// ----------------------------------------------------------------

#include "customer.h"
#include "store.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//overloaded << operator to print customer name to console
ostream& operator <<(ostream& out, Customer &rhs)
{
    out << rhs.getName();
    return out;
};

//-----------------------------------------------------------------
//constructor; ID number, first name, last name
Customer::Customer(int a, string b , string c)
{
    setID(a);
    setName(b, c);
};

Customer::~Customer()
{

};

//-----------------------------------------------------------------
//name setter function; first and last name
void Customer::setName(string first, string last)
{
    this->custFirst = first;
    this->custLast = last;
};

//-----------------------------------------------------------------
//name setter function; full name
void Customer::setName(string name)
{
    std::stringstream s(name);
    s >> custFirst >> custLast;
};

//-----------------------------------------------------------------
//ID number setter function
void Customer::setID(int number)
{
    this->id = number;
};


//-----------------------------------------------------------------
//name getter function
string Customer::getName()
{
    return custFirst + " " + custLast;
};

//-----------------------------------------------------------------
//ID number getter function
int Customer::getID()
{
    return id;
};

//-----------------------------------------------------------------
//print current inventory
void Customer::printCurrInventory()
{
    for (auto i = currentMovies.begin(); i != currentMovies.end(); i++)
    {
        cout << *i << endl;
    };
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
    int key;
    string temp;
    if (movie.getGenre() == "F")
    {
        temp = "F" + to_string(movie.getReleaseYear()) + movie.getTitle();
        key = Store::cstoi(temp);
    }
    else
    {
        temp = "D" + movie.getDirector() + movie.getTitle();
        key = Store::cstoi(temp);
    }
    
	

    //edge-case check if movie exists and in stock
    if (Store::StoreInventory.search(key) == nullptr ||
    Store::StoreInventory.search(key)->getStock() == 0)
    {
        string errorM = "Sorry! " + movie.getReleaseYear() + 
            movie.getTitle() + " is unavailable.";
        transactionHistory.push_back(errorM);
    }
    else
    {
        addMovie(movie);  
        Store::StoreInventory.search(key)->
            setStock(Store::StoreInventory.search(key)->getStock() - 1);
        string message = "User borrowed: " + movie.getReleaseYear()
            + movie.getTitle(); 
        transactionHistory.push_back(message);
    };
};

void Customer::borrowMovie(Classic &movie)
{
    int key;
    string temp;
    string releasedate = movie.getReleaseDate();
    string acto = movie.getActor();
    temp = "C" + releasedate + acto;
    key = Store::cstoi(temp);
    
	

    //edge-case check if movie exists and in stock
    if (Store::StoreInventory.classicSearch(key) == nullptr ||
    Store::StoreInventory.classicSearch(key)->getStock() == 0)
    {
        string errorM = "Sorry! " + movie.getReleaseYear() + 
            movie.getTitle() + " is unavailable.";
        transactionHistory.push_back(errorM);
    }
    else
    {
        addMovie(movie);  
        Store::StoreInventory.classicSearch(key)->
            setStock(Store::StoreInventory.classicSearch(key)->getStock() - 1);
        string message = "User borrowed: " + movie.getReleaseYear()
            + movie.getTitle(); 
        transactionHistory.push_back(message);
    };
};

bool Customer::operator == (Customer &rhs)
{
    return (this->getID() == rhs.getID()) && (this->getName() == rhs.getName());
};

//-----------------------------------------------------------------
//return function; stock + 1
void Customer::returnMovie(Movie &movie)
{
    //edge-case check if customer has the movie checked out
    bool movieBorrowed = false;
    
    for (long long unsigned int i = 0; i < currentMovies.size(); i++)
    {
        if (currentMovies.at(i) == movie)
        {
            vector<Movie>::iterator it;
            it = currentMovies.begin() + i; // might need to be i - 1
            currentMovies.erase(it);
            movieBorrowed = true;
        };
    };

    //if not in customer inventory, print error
    if (movieBorrowed == false)
    {
        string errorM = "Sorry! " + movie.getReleaseYear() + 
            movie.getTitle() + " is not in User's inventory.";
        transactionHistory.push_back(errorM);
    }
    else //perform return otherwise
    {
        string temp;
        if (movie.getGenre() == "F")
        {
            temp = "F" + Store::trim(movie.getTitle()) + to_string(movie.getReleaseYear());
        }
        if (movie.getGenre() == "D")
        {
            temp = "D" + Store::trim(movie.getDirector()) + Store::trim(movie.getTitle());
        }
        

	    int key = Store::cstoi(temp);
        Store::StoreInventory.search(key)->
            setStock(Store::StoreInventory.search(key)->getStock() + 1);
        string message = "User returned: " + movie.getReleaseYear() 
            + movie.getTitle(); 
        transactionHistory.push_back(message);    
    };
};

void Customer::returnMovie(Classic &movie)
{
    //edge-case check if customer has the movie checked out
    bool movieBorrowed = false;
    
    for (long long unsigned int i = 0; i < currentMovies.size(); i++)
    {
        if (currentMovies.at(i) == movie)
        {
            vector<Movie>::iterator it;
            it = currentMovies.begin() + i; // might need to be i - 1
            currentMovies.erase(it);
            movieBorrowed = true;
        };
    };

    //if not in customer inventory, print error
    if (movieBorrowed == false)
    {
        string errorM = "Sorry! " + movie.getReleaseYear() + 
            movie.getTitle() + " is not in User's inventory.";
        transactionHistory.push_back(errorM);
    }
    else //perform return otherwise
    {
        string temp;
        
        temp = "C" + movie.getReleaseDate() + movie.getActor();

	    int key = Store::cstoi(temp);
        Store::StoreInventory.search(key)->
            setStock(Store::StoreInventory.classicSearch(key)->getStock() + 1);
        string message = "User returned: " + movie.getReleaseYear() 
            + movie.getTitle(); 
        transactionHistory.push_back(message);    
    };
};

//-----------------------------------------------------------------
//prints customer’s history of movie inventory to console
void Customer::printInventoryHistory()
{
    for (long long unsigned int i = 0; i < transactionHistory.size(); i++)
    {
        int it = (int) i;
        cout << transactionHistory.at(it) << endl;
    }
};
