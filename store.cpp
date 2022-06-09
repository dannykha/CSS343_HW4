// ----------------------------------------------------------------
// store.h
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 8, 2022
// ----------------------------------------------------------------
// Purpose - develops Store class
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// - uses a file stream to read from text files
// - files are to be located with the program files
// ----------------------------------------------------------------

#include "store.h"
#include "customer.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstddef>

using namespace std;

//initialize MovieInventory object
MovieInventory Store::StoreInventory;

//-----------------------------------------------------------------
//constant static string variable used in trim; delimitter
const string Store::WHITESPACE =  " \n\r\t\f\v";

//-----------------------------------------------------------------
//default constructor
Store::Store() {}

//-----------------------------------------------------------------
//destructor
Store::~Store() {}

//-----------------------------------------------------------------
//constructor with inital store name
Store::Store(string &theName)
{

    this->storeName = theName;
}

//-----------------------------------------------------------------
//store name getter
string Store::getStoreName()
{
    return storeName;
};

//-----------------------------------------------------------------
//custom string to integer function
int Store::cstoi(string & in)
{
    int sum = 0;
    for (long long unsigned int i{0};  i < in.length(); i++)
    {
        sum += in[i];
    }
    return sum;
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
    string line;
    
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
        v.clear();
        getline(data, line);
        stringstream iss;
        iss << line;
        string substr;
        while (iss >> substr)
        {
            v.push_back(trim(substr));
            
        }
        currentCommand = v[0];
        switch( (int)currentCommand[0] )
        {
            case 66: // (B)orrow
            {
                customerID = v[1];
                mediaType = v[2];
                if (mediaType != "D")
                {
                    cerr << "Error: invalid media type '" << mediaType 
                        << "'" << endl;
                }
                else 
                {
                    movieType = v[3];
                    if (movieType == "F") // Comedy
                    {
                        
                        string title;
                        string releaseYear;

                        
                        int last = v.size();
                        //char ch = ',';
                        for (long long unsigned int i{4}; i < v.size() - 1; i++)
                        {
                            if (i < v.size() - 2)
                            {
                                title.append(v[i] + " ");
                            }
                            else
                            {
                                string lastNoComma = v[i];
                                lastNoComma.erase(remove(lastNoComma.begin(), 
                                    lastNoComma.end(), ','), lastNoComma.end());
                                title.append(lastNoComma);
                            }
                            
                        }
                        releaseYear = v[last-1];
                        string key = "F" + trim(title) + releaseYear;
                        
                        Customer* cust = 
                        Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = StoreInventory.search(cstoi(key));
                        if (movie == nullptr || cust == nullptr)
                        {
                            break;
                        }
                        cust->borrowMovie(*movie);
                    }
                    else if (movieType == "D") // Drama
                    {
                        char ch = ',';
                        size_t found;
                        string director;
                        string toAdd;
                        int i{4};
                        do {
                            
                            toAdd = v[i] + " ";
                            director.append(toAdd);
                            
                            found = v[i].find_last_of(ch);
                            if (found != string::npos)
                            {
                                break;
                            }
                            i++;
                        } while ((true));

                        
                        director.erase(remove(director.begin(), director.end(),
                             ','), director.end());
                        director = trim(director);
                        
                        string title;
                        i++;
                        long long unsigned int x = i;
                        for (long long unsigned int i{x}; i < v.size(); i++)
                        {
                            if (i < v.size() - 1)
                            {
                                title.append(v[i] + " ");
                            }
                            else
                            {
                                string lastNoComma = v[i];
                                lastNoComma.erase(remove(lastNoComma.begin(), 
                                    lastNoComma.end(), ','), lastNoComma.end());
                                title.append(lastNoComma);
                            }
                        }
                        string key = "D" + trim(director) + trim(title);
                        Customer* cust = 
                        Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = StoreInventory.search(cstoi(key));
                        if (movie == nullptr || cust == nullptr)
                        {
                            break;
                        }
                        cust->borrowMovie(*movie);
                    }
                    else if (movieType == "C") // Classic
                    {
                        string month;
                        string year;
                        string actorFirst;
                        string actorLast;

                        month = v[4];
                        year = v[5];
                        actorFirst = v[6];
                        actorLast = v[7];
                        string key = "C" + month + " " + year + actorFirst + 
                            " " + actorLast;
                        Customer* cust = 
                        Store::StoreCustomerDatabase.search(stoi(customerID));
                        int ccKey = cstoi(key);
                        Classic* classicPtr = 
                            StoreInventory.classicSearch(ccKey);
                        if (classicPtr == nullptr || cust == nullptr)
                        {
                            break;
                        }
                        cust->borrowMovie(*classicPtr);
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
                customerID = v[1];
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
                customerID = v[1];
                mediaType = v[2];
                if (mediaType != "D")
                {
                    cerr << "Error: invalid media type '" << mediaType 
                        << "'" << endl;
                }
                else
                {
                    movieType = v[3];
                    if (movieType == "F") // Comedy
                    {
                        string title;
                        string releaseYear;
                        int last = v.size();
                        //char ch = ',';
                        for (long long unsigned int i{4}; i < v.size() - 1; i++)
                        {
                            if (i < v.size() - 2)
                            {
                                title.append(v[i] + " ");
                            }
                            else
                            {
                                string lastNoComma = v[i];
                                lastNoComma.erase(remove(lastNoComma.begin(), 
                                    lastNoComma.end(), ','), lastNoComma.end());
                                title.append(lastNoComma);
                            }
                            
                        }
                        releaseYear = v[last-1];
                        string key = "F" + trim(title) + releaseYear;

                        Customer* cust = 
                        Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = Store::StoreInventory.search(cstoi(key));
                        cust->returnMovie(*movie);
                    }   
                    else if (movieType == "D") // Drama
                    {
                        char ch = ',';
                        size_t found;
                        string director;
                        string toAdd;
                        int i{4};
                        do {
                            
                            toAdd = v[i] + " ";
                            director.append(toAdd);
                            
                            found = v[i].find_last_of(ch);
                            if (found != string::npos)
                            {
                                break;
                            }
                            i++;
                        } while ((true));

                        
                        director.erase(remove(director.begin(), director.end(),
                             ','), director.end());
                        director = trim(director);
                        
                        string title;
                        i++;
                        long long unsigned int x = i;
                        for (long long unsigned int i{x}; i < v.size(); i++)
                        {
                            if (i < v.size() - 1)
                            {
                                title.append(v[i] + " ");
                            }
                            else
                            {
                                string lastNoComma = v[i];
                                lastNoComma.erase(remove(lastNoComma.begin(), 
                                    lastNoComma.end(), ','), lastNoComma.end());
                                title.append(lastNoComma);
                            }
                        }
                        string key = "D" + trim(director) + trim(title);
                        Customer* cust = 
                          Store::StoreCustomerDatabase.search(stoi(customerID));
                        Movie* movie = Store::StoreInventory.search(cstoi(key));
                        cust->returnMovie(*movie);
                    }
                    else if (movieType == "C") // Classic
                    {
                        string month;
                        string year;
                        string actorFirst;
                        string actorLast;

                        month = v[4];
                        year = v[5];
                        actorFirst = v[6];
                        actorLast = v[7];
                        string key = "C" + month + " " + year + actorFirst + " "+
                            actorLast;
                        Customer* cust = 
                        Store::StoreCustomerDatabase.search(stoi(customerID));
                        Classic* movie = 
                        Store::StoreInventory.classicSearch(cstoi(key));
                        cust->returnMovie(*movie);
                    }
                    else
                    {
                        cerr << "Error: invalid movie type '" 
                            << movieType << "'" << endl;
                    }
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
        cout << customerID << "         " << custFirst << "   " 
            << custLast << endl; 
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
    string line;
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
        string substr;
        stringstream iss;
        getline(data, line);
        iss << line;
        while (getline(iss, substr, ','))
        {
            v.push_back(trim(substr));
        }
        
        if (line == "")
        {
            break;
        }
        currentMovie = v[0];
        stringstream ss(v[4]);
        switch( (int)currentMovie[0] )
        {
            case 67: // C
            {
                ss >> actorFirst;
                ss >> actorLast;
                ss >> classicMonth;
                ss >> classicYear;
                v[1] = trim(v[1]);
                string toStock = v[1];
                int actualStock = stoi(toStock);
                Classic *classics = new Classic(actualStock, v[2], v[3],
                     actorFirst, actorLast, classicMonth, classicYear);
                string keyC = "C" + to_string(classicMonth) + " " 
                    + to_string(classicYear) + actorFirst + " " + actorLast;
                int cKey = cstoi(keyC);
                Store::StoreInventory.insert(cKey, classics);
            }
                break;
            case 68: // D
            {
                Drama *dramas = new Drama(stoi(v[1]), v[2], v[3], stoi(v[4]));
                string keyD = "D" + v[2] + v[3];
                int Dkey = cstoi(keyD);
                Store::StoreInventory.insert(Dkey, dramas);
            }
                break;
    
            case 70: // F
            {
                Comedy *comedies = new Comedy(stoi(v[1]), v[2],
                     v[3], stoi(v[4]));
                string keyF = "F" + v[3] + v[4];
                int Fkey = cstoi(keyF);
                Store::StoreInventory.insert(Fkey, comedies);
            }
                break;
            default:
            {
                cerr << "Error: invalid movie type '" << currentMovie[0]
                    << "'" << endl;
                break;
            }
        }
    }
}


 
string Store::ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
string Store::rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
string Store::trim(const std::string &s) {
    return rtrim(ltrim(s));
}