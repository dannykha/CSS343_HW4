#include "store.h"
#include "customerdatabase.h"

Store::Store(string &theName)
{
    this->storeName = theName;

}

void Store::readCommands(string &fileName)
{
    string currentCommand = "";
    ifstream data;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    data >> currentCommand;
    while ( !data.eof() )
    {
        switch( (int)currentCommand[0] )
        {
            case 66: // B

                break;
            case 72: // H

                break;
            case 73: // I

                break;
            case 82: // R

                break;
            default:
                cerr << "Error: invalid command type '" << currentCommand[0] << "'" << endl;
        }
    }
}

void Store::readCustomers(string &fileName)
{
    int customerID;
    string custFirst;
    string custLast;
    ifstream data;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    
    while ( !data.eof() )
    {
        data >> customerID >> custFirst >> custLast;
        Customer *cust = new Customer(customerID, custFirst, custLast);
        StoreCustomerDatabase.insert(customerID, cust);
        // DONT FORGET TO DESTRUCT
    }
}

void Store::readMovies(string &fileName)
{
    int stock;
    string director;
    string title;
    int year;
    string majorActor;
    string currentMovie = "";
    ifstream data;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    data >> currentMovie;
    while ( !data.eof() )
    {
        switch( (int)currentMovie[0] )
        {
            case 67: // C
                
                break;
            case 68: // D

                break;
            case 70: // F
                
                break;
            default:
                cerr << "Error: invalid movie type '" << currentMovie[0] << "'" << endl;
        }
    }
}