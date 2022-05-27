#ifndef BORROW_H
#define BORROW_H
#pragma once;
#include "movie.h"
#include "customer.h"

class Borrow
{
    public:
        Borrow(Customer *custPtr, Movie *moviePtr);
        ~Borrow() {};
        virtual void printBorrow();
        virtual void executeBorrow();
    private:
        Movie *moviePtr;
        Customer *custPtr;
        int tempStock;
};
#endif // BORROW_H