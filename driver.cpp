#include <iostream>
#include "store.h"
#include "storebuilder.h"
using namespace std;

int main()
{
    StoreBuilder Stor;
    string storeName = "store0";
    Stor.addStore(storeName);
    string storeName = "store1";
    
    string commandsFile = "data4commands.txt";
    Stor.getStore(0).readCommands(commandsFile);
    
    string customerFile = "data4commands.txt";
    Stor.getStore(0).readCustomers(customerFile);
    
    string moviesFile = "data4commands.txt";
    Stor.getStore(0).readMovies(moviesFile);
}

