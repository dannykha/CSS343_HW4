#ifndef HASTABLE_H
#define HASTABLE_H
#pragma once
#define TABLE_SIZE 250
#include "customer.h"

using namespace std;

class HashElementCust
{
    public:
        int key;
        Customer *customer;
        Customer temp = Customer(0, "first", "last");
	    Customer* tempPtr = &temp;
        HashElementCust()
        {
            key = 0;
            customer = tempPtr;
        }
        HashElementCust(int k, Customer *cust)
        {
            key = k;
            customer = cust;
        }
};

class CustomerDatabase
{
    public:
        CustomerDatabase();
        ~CustomerDatabase();
        void destroy();
        int hashFunction(int key);
        void insert(int key, Customer *custPtr);
        Customer* search(int key);
        void remove(int key);
    private:
        HashElementCust table[TABLE_SIZE];
};

#endif // HASTABLE_H