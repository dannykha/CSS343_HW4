#include "store.h"
#include "customerdatabase.h"

Store::Store()
{
    Inventory StoreInventory = new Inventory;
    CustomerDatabase StoreCustomerDatabase = new CustomerDatabase;

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
    string forHash;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    
    while ( !data.eof() )
    {
        data >> customerID >> custFirst >> custLast;
        forHash = (custFirst.append(custLast.append(to_string(customerID))));
        // add a customer with hash of the string of all the above
        // and Customer(customerID, custFirst, custLast);
    }
}

void Store::readMovies(string &fileName)
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
            case 67: // C
            
                break;
            case 68: // D

                break;
            case 70: // F
                
                break;
            default:
                cerr << "Error: invalid movie type '" << currentCommand[0] << "'" << endl;
        }
    }
}