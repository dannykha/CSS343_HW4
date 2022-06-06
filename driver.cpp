// ----------------------------------------------------------------
// driver.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 6, 2022
// ----------------------------------------------------------------
// Purpose - initializes the store, customers, and movies before
// performing the actions ordered by each customer
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - data files are provided in the program files
// ----------------------------------------------------------------

#include <iostream>
#include "store.h"
#include "storebuilder.h"
using namespace std;

int main()
{
    //initliaze store
    StoreBuilder Stor;
    string storeName = "store0";
    Stor.addStore(storeName);
    
    //read commands from txt file and initialize
    string commandsFile = "data4commands.txt";
    Stor.getStore(0).readCommands(commandsFile);
    
    //read customers from txt file and initialize
    string customerFile = "data4customers.txt";
    Stor.getStore(0).readCustomers(customerFile);
    
    //read movies from txt file and initalize
    string moviesFile = "data4movies.txt";
    Stor.getStore(0).readMovies(moviesFile);
}

