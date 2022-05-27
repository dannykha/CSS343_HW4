#include "return.h"
#include <iostream>
using namespace std;

Return::Return(Customer *cust, Movie *movie)
{
    moviePtr = movie;
    custPtr = cust;
    tempStock = 0;
}

void Return::printReturn()
{
    cout << "  Returned: " << moviePtr->getGenre() << ", " << tempStock;
	cout << ", " << moviePtr->getTitle() << ", " << moviePtr->getDirector();
	cout << endl;
}

void Return::executeReturn()
{
    tempStock = 0;
    if (custPtr->movieBorrowed(moviePtr))
    {
        custPtr->addCommand(this);
        custPtr->returnMovie(moviePtr);
        moviePtr->returnMovie();
        tempStock = moviePtr->getStock();
    }
    else
    {
        cout << "Return not complete";
    }
}