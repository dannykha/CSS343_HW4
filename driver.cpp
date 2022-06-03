#include <iostream>
#include "store.h"
using namespace std;

int main()
{
    StoreBuilder Stor;
    Stor.newStore("store1");
    string storeName = "store1";

    Stor.getStore(storeName).readCommands("data4commands.txt");
    Stor.getStore(storeName).readCustomers("data4customers.txt");
    Stor.getStore(storeName).readMovies("data4movies.txt");
}

