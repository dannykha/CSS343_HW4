#include "borrow.h"
#include <iostream>
using namespace std;

Borrow::Borrow(Customer *cust, Movie *movie)
{
    moviePtr = movie;
    custPtr = cust;
    tempStock = 0;
}

void Borrow::printBorrow()
{
    cout << " Borrowed: " << moviePtr->getGenre() << ", " << tempStock;
    cout << "," << moviePtr->getTitle() << "," << moviePtr->getDirector();
    cout << endl;
}

void Borrow::executeBorrow()
{
    tempStock = 0;
    if (moviePtr->getStock() > 0)
    {
        custPtr->addCommand(this);
        custPtr->addMovie(moviePtr);
        moviePtr->borrowMovie();
        tempStock = moviePtr->getStock();
    }
    else
    {
        cout << "Movie out of stock: ";
        moviePtr->print();
    }
}
