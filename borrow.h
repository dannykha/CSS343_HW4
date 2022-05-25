#ifndef BORROW_H
#define BORROW_H
#pragma once;
#include "movie.h"
#include "customer.h"

class Borrow
{
    public:
        bool executeBorrow(Movie &);
    private:
        Movie *movie;
        Customer *cust;
        int tempStock;
};
#endif // BORROW_H