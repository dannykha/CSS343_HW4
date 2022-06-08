// ----------------------------------------------------------------
// store.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - develops Store class
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - uses a file stream to read from text files
// - files are to be located with the program files
// ----------------------------------------------------------------

#include "store.h"

//initialize MovieInventory object
MovieInventory Store::StoreInventory;

//default constructor
Store::Store()
{
    
}

//-----------------------------------------------------------------
//destructor
Store::~Store()
{

}

//-----------------------------------------------------------------
//constructor with inital store name
Store::Store(string &theName)
{
    this->storeName = theName;
}

//-----------------------------------------------------------------
//read commands function
void Store::readCommands(string &fileName)
{
    string currentCommand = "";
    string customerID;
    string mediaType;
    string movieType;
    string movieData;
    ifstream data;
    vector<string> v;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    while ( !data.eof() )
    {
        data >> currentCommand;
        switch( (int)currentCommand[0] )
        {
            case 66: // (B)orrow
            {
                data >> customerID;
                data >> mediaType;
                if (mediaType != "D")
                {
                    cerr << "Error: invalid media type '" << mediaType 
                        << "'" << endl;
                }
                else 
                {
                    data >> movieType;
                    if (movieType == "F") // Comedy
                    {
                        string title;
                        string releaseYear;

                        getline(data, title, ',');
                        data >> releaseYear;
                        string key = "F" + releaseYear + title;
                        Customer* cust = 
                            Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = StoreInventory.search(stoi(key));
                        cust->borrowMovie(*movie);
                    }
                    else if (movieType == "D") // Drama
                    {
                        string director;
                        string title;

                        getline(data, director, ',');
                        getline(data, title, ',');
                        string key = "D" + director + title;
                        Customer* cust = 
                            Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = StoreInventory.search(stoi(key));
                        cust->borrowMovie(*movie);
                    }
                    else if (movieType == "C") // Classic
                    {
                        string month;
                        string year;
                        string actorFirst;
                        string actorLast;

                        data >> month;
                        data >> year;
                        data >> actorFirst;
                        data >> actorLast;
                        string key = "C" + month + year + actorFirst + 
                            actorLast;
                        Customer* cust = 
                            Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = StoreInventory.search(stoi(key));
                        cust->borrowMovie(*movie);
                    }
                    else
                    {
                        cerr << "Error: invalid movie type '" 
                            << movieType << "'" << endl;
                    }
                }
            }
                break;
            case 72: // (H)istory
            {
                data >> customerID;
                Store::StoreCustomerDatabase.search(
                    stoi(customerID))->printInventoryHistory();
            }
                break;
            case 73: // (I)nventory
            {
                Store::StoreInventory.printInventory();
            }
                break;
            case 82: // (R)eturn
            {
                data >> movieType;
                 if (movieType == "F") // Comedy
                    {
                        string title;
                        string releaseYear;

                        getline(data, title, ',');
                        data >> releaseYear;
                        string key = "F" + releaseYear + title;
                        Customer* cust = 
                            Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = Store::StoreInventory.search(stoi(key));
                        cust->returnMovie(*movie);
                    }
                    else if (movieType == "D") // Drama
                    {
                        string director;
                        string title;

                        getline(data, director, ',');
                        getline(data, title, ',');
                        string key = "D" + director + title;
                        Customer* cust = 
                            Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = Store::StoreInventory.search(stoi(key));
                        cust->returnMovie(*movie);
                    }
                    else if (movieType == "C") // Classic
                    {
                        string month;
                        string year;
                        string actorFirst;
                        string actorLast;

                        data >> month;
                        data >> year;
                        data >> actorFirst;
                        data >> actorLast;
                        string key = "C" + month + year + actorFirst + 
                            actorLast;
                        Customer* cust = 
                            Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = 
                            Store::StoreInventory.search(stoi(key));
                        cust->returnMovie(*movie);
                    }
                    else
                    {
                        cerr << "Error: invalid movie type '" 
                            << movieType << "'" << endl;
                    }
            }
                break;
            default:
            {
                cerr << "Error: invalid command type '" << 
                    currentCommand[0] << "'" << endl;
            }
        }
    }
}

//-----------------------------------------------------------------
//read customer function
void Store::readCustomers(string &fileName)
{
    int customerID;
    string custFirst;
    string custLast;
    ifstream data;
    cout << "Opening Customer file" << endl;
    data.open(fileName);
    if (!data)
    {
        cerr << "Error: file '" << fileName << "' could not be opened" << endl;
        exit(1);
    }
    cout << "Customer file opened" << endl;
    while ( !data.eof() )
    {
        data >> customerID >> custLast >> custFirst;
        cout << "Customer ready to process with the following data" << endl;
        cout << "Customer ID - First Name - Last Name" << endl;
        cout << customerID << "       " << custFirst << " " << custLast << endl; 
        Customer *cust = new Customer(customerID, custFirst, custLast);
        cout << "Customer created successfully" << endl;
        cout << "Adding customer to database" << endl;
        StoreCustomerDatabase.insert(customerID, cust);
        cout << "Customer added successfully" << endl << endl;
        // DONT FORGET TO DESTRUCT
    }
}

//-----------------------------------------------------------------
//read movies function
void Store::readMovies(string &fileName)
{
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
        v.clear();
        data >> currentMovie;
        for (int i = 0; i < 4; i++) {
            string substr;
            getline(data, substr, ','); // May be wrong for getline to seperate the commas, movie label may not be in the line
            // data may be starting at the stock value
            v.push_back(substr);
        }
        stringstream ss(v[3]);
        switch( (int)currentMovie[0] )
        {
            case 67: // C
            {
                ss >> actorFirst;
                ss >> actorLast;
                ss >> classicMonth;
                ss >> classicYear;
                Classic *classics = new Classic(stoi(v[0]), v[1], v[2], actorFirst, actorLast, classicMonth, classicYear);
                Store::StoreInventory.insert(classics);
            }
                break;
            case 68: // D
            {
                Drama *dramas = new Drama(stoi(v[0]), v[1], v[2], stoi(v[3]));
                Store::StoreInventory.insert(dramas);
            }
                break;
    
            case 70: // F
            {
                Comedy *comedies = new Comedy(stoi(v[0]), v[1], v[2], stoi(v[3]));
                Store::StoreInventory.insert(comedies);
            }
                break;
            default:
            {
                cerr << "Error: invalid movie type '" << currentMovie[0] << "'" << endl;
                break;
            }
        }
    }
}