#ifndef HISTORY_H
#define HISTORY_H
#pragma once
#include "customer.h"

class History
{
    public:
        History(Customer *cust);
        ~History() {};
        virtual void printHistory();
        virtual void executeHistory();
    private:
        Customer *custPtr;
};
#endif // HISTORY_H