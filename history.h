#ifndef HISTORY_H
#define HISTORY_H
#pragma once;
#include "customer.h"

class History
{
    public:
        void executeHistory();
    private:
        Customer *cust;
};
#endif // HISTORY_H