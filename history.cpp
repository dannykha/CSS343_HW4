#include "history.h"
#include <iostream>

History::History(Customer *cust)
{
    custPtr = cust;
}

void History::printHistory()
{
    cout << "History: " << custPtr->getName();
}

void History::executeHistory()
{
    custPtr->printActionHistory();
}