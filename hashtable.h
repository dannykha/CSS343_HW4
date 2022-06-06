#ifndef HASTABLE_H
#define HASTABLE_H
#pragma once
#define TABLE_SIZE 250
#include "customer.h"

using namespace std;

class HashElement
{
    public:
        int key;
        Customer *customer;
        HashElement(int k, Customer *cust) {
            key = k;
            customer = cust;
        }
};

class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void destroy();
        int hashFunction(int key);
        void insert(int key, Customer *custPtr);
        Customer* search(int key);
        void remove(int key);
    private:
        HashElement **table;
};


#endif // HASTABLE_H