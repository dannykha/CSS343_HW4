// ----------------------------------------------------------------
// customerdatabase.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - develops CustomerDatabase class to implement HashTable
// to initialize each customer, ID pair
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "customerdatabase.h"
#include <iostream> 

using namespace std;

//constructor
CustomerDatabase::CustomerDatabase()
{
	for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = HashElementCust();
    }
}

//-----------------------------------------------------------------
//destructor
CustomerDatabase::~CustomerDatabase()
{
	destroy();
}

//-----------------------------------------------------------------
//destructor helper
void CustomerDatabase::destroy()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		delete table[i].customer;
		delete table[i].tempPtr;
		table[i].customer = nullptr;
		table[i].tempPtr = nullptr;
	}
	delete[] table;
}

//-----------------------------------------------------------------
//hash function, turns key into a hashvalue
int CustomerDatabase::hashFunction(int key)
{
	int modVal = TABLE_SIZE;
	return key % modVal;
}

//-----------------------------------------------------------------
//insert function
void CustomerDatabase::insert(int key, Customer *custPtr)
{
	//hash the user id
	int hash = hashFunction(key);
	bool good = true;

	while (hash < TABLE_SIZE)
	{
		//this makes sure the spot you're trying to insert is not a duplicate account
		if (table[hash].customer->getName() == custPtr->getName() )
		{
			if (table[hash].key == hashFunction(custPtr->getID()))
			{
				cout << "Duplicate accounts not allowed, " 
				<< "skipping account creation" << endl;
				return;
			}
		}

		//find a good spot for our insertion
		string defaultName = "first last";
		if(table[hash].customer->getName() == defaultName)
		{
			if (table[hash].key == 0)
			{
				// inserts the account
				table[hash].key = hashFunction(key);
				table[hash].customer = custPtr;
				return;
			}
		}
		hash++; 
		// goes over array 1.5x, can make faster, by remembering 
		//initial hash value, and stopping once it reaches that, stopping
		// it from going over what it's already gone over
		// during the first half of checks
		if (good && hash == TABLE_SIZE)
		{
			hash = 0;
			good = false;
		}
	}
	
}

//-----------------------------------------------------------------
//search function
Customer* CustomerDatabase::search(int key)
{
	//look for key in spot of hash, if not there
	//check if there by checking key value against the customer's ID!!
	// keep going, do the 1.5x search for input again, then return customer 
	//doesn't exist
	
	int hash = hashFunction(key);
	//make a copy of inital hash to keep constant for already visited check
	//int hashVisited = hash;
	bool good = true;

	while (hash < TABLE_SIZE)
	{
		if (table[hash].customer->getID() == key)
		{
			return table[hash].customer;
		}

		if (good && hash == TABLE_SIZE)
		{
			hash = 0;
			good = false;
		}

		/* idea to only search the other half rather than 1.5 times?
		//hashVisted check at the bottom to get through inital
		//iteration first
		if (hash == hashVisted)
		{
			break;
		}
		*/
	}
}

//-----------------------------------------------------------------
//remove function
void CustomerDatabase::remove(int key)
{
	int hash = hashFunction(key);
	// do the verification to be sure it's the correct spot
	// aka copy paste search
	// but instead of returning when found
	// re-set to default value
	//    Customer temp = Customer(0, "first", "last");
	//    Customer* tempPtr = &temp;
    //    HashElementCust()
    //    {
    //        key = 0;
    //        customer = tempPtr;
    //    }
}
