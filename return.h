#ifndef RETURN_H
#define RETURN_H
#pragma once;
#include "movie.h"
#include "customer.h"

class Return
{
    public:
        bool executeReturn(Movie &);
    private:
        Movie *movie;
        Customer *cust;
        int tempStock;
};
#endif // RETURN_H