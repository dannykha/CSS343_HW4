#ifndef RETURN_H
#define RETURN_H
#pragma once;
#include "movie.h"
#include "customer.h"

class Return
{
    public:
        Return(Customer *custPtr, Movie *moviePtr);
        virtual ~Return() {};
        virtual void printReturn();
        virtual void executeReturn();
    private:
        Movie *moviePtr;
        Customer *custPtr;
        int tempStock;
};
#endif // RETURN_H