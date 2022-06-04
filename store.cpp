
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
    string actorFirst;
    string actorLast;
    int classicMonth;
    int classicYear;
    string currentMovie = "";
    vector<string> v;
    ifstream data;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    while ( !data.eof() )
    {
        data >> currentMovie;
        string substr;
        getline(data, substr, ','); // May be wrong for getline to seperate the commas, movie label may not be in the line
        // data may be starting at the stock value
        v.push_back(substr);
        stringstream ss(v[4]);
        switch( (int)currentMovie[0] )
        {
            case 67: // C
                // Ingrid Bergman 8 1942
                ss >> actorFirst;
                ss >> actorLast;
                ss >> classicMonth;
                ss >> classicYear;
                Classic *classics = new Classic(stoi(v[1]), v[2], v[3], actorFirst, actorLast, classicMonth, classicYear);
                StoreInventory.insert(classics);
                break;
            case 68: // D
                Drama *dramas = new Drama(stoi(v[1]), v[2], v[3], stoi(v[4]));
                StoreInventory.insert(dramas);
                break;
            case 70: // F
                Comedy *comedies = new Comedy(stoi(v[1]), v[2], v[3], stoi(v[4]));
                StoreInventory.insert(comedies);
                break;
            default:
                cerr << "Error: invalid movie type '" << currentMovie[0] << "'" << endl;
        }
    }
}