// ----------------------------------------------------------------
// MovieInventory.cpp
// Andrew Demaris, Danny Kha, Sara Saleh CSS343B 
// Creation Date: May 18, 2022
// Date of Last Modification: June 7, 2022
// ----------------------------------------------------------------
// Purpose - develops MovieInventory class to implement HashTable
// to initialize each customer, ID pair
// ----------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// ----------------------------------------------------------------

#include "movieinventory.h"
#include "store.h"
#include <iostream> 

using namespace std;

//constructor
MovieInventory::MovieInventory()
{
	for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = HashElementMovie();
    }
}

//-----------------------------------------------------------------
//destructor
MovieInventory::~MovieInventory()
{
	destroy();
}

//-----------------------------------------------------------------
//destructor helper
void MovieInventory::destroy()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		
		table[i].movie = nullptr;
	}
	
}

//-----------------------------------------------------------------
//hash function, turns key into a hashvalue
int MovieInventory::hashFunction(int key)
{
	int modVal = TABLE_SIZE;
	return key % modVal;
}

//-----------------------------------------------------------------
//insert function
void MovieInventory::insert(int key, Movie *moviPtr)
{
	//hash the user id
	int hash = hashFunction(key);
	bool good = true;

	while (hash < TABLE_SIZE)
	{
		if (hash == 0)
		{
			hash = 1;
		}
		if (table[hash].key == 0)
		{
			// inserts the account
			table[hash].key = hash;
			table[hash].movie = moviPtr;
			return;
		}

		//this makes sure the spot you're trying to insert is not a duplicate account
		// if (table[hash].movie->getName() == moviPtr->getName() )
		// {
		// 	cout << "Duplicate accounts not allowed, " 
		// 	<< "skipping account creation" << endl;
		// 	return;
		// }

		//find a good spot for our insertion

		hash++; 
		// goes over array 1.5x, can make faster, by remembering 
		//initial hash value, and stopping once it reaches that, stopping
		// it from going over what it's already gone over
		// during the first half of checks
		if (good && hash == TABLE_SIZE)
		{
			hash = 1;
			good = false;
		}
	}
}

void MovieInventory::printInventory()
{
	for(int i{0}; i < TABLE_SIZE; i++)
	{
		if (table[i].key != 0)
		{
			if (table[i].isClassic)
			{
				cout << table[i].classic->getTitle() << endl;
			} 
			else
			{
				cout << table[i].movie->getTitle() << endl;;
			}
			
		}
	}
}

//-----------------------------------------------------------------
// classic movie insert
void MovieInventory::insert(int key, Classic* classicPtr)
{
	//hash the user id
	int hash = hashFunction(key);
	bool good = true;

	while (hash < TABLE_SIZE)
	{
		if (hash == 0)
		{
			hash = 1;
		}
		if (table[hash].key == 0)
		{
			// inserts the account
			table[hash].key = hash;
			table[hash].classic = classicPtr;
			table[hash].isClassic = true;
			return;
		}

		//this makes sure the spot you're trying to insert is not a duplicate account
		// if (table[hash].movie->getName() == moviPtr->getName() )
		// {
		// 	cout << "Duplicate accounts not allowed, " 
		// 	<< "skipping account creation" << endl;
		// 	return;
		// }

		// if the titles are the same then increment the stock of the movies
		// that we have of it
		//stock = classicPtr->getTotalStock();
		if (table[hash].isClassic)
		{
			if (table[hash].classic->getTitle() == classicPtr->getTitle())
			{
				if (table[hash].classic->getActor() == classicPtr->getActor())
				{
					if (table[hash].classic->getReleaseDate() == classicPtr->getReleaseDate())
					{
						//identical movie gets it stock incremented
						table[hash].classic->setStock(table[hash].classic->getStock() + classicPtr->getStock());
						return;
					}
				}
				int newTotal = table[hash].classic->getStock() + classicPtr->getStock();
				table[hash].classic->setTotalStock(newTotal);
				classicPtr->setTotalStock(newTotal);
			}
		}
		
		
		//table[hash].classic->setStock(stock);

		//find a good spot for our insertion

		hash++; 
		// goes over array 1.5x, can make faster, by remembering 
		//initial hash value, and stopping once it reaches that, stopping
		// it from going over what it's already gone over
		// during the first half of checks
		if (good && hash == TABLE_SIZE)
		{
			hash = 1;
			good = false;
		}
	}
}

//-----------------------------------------------------------------
//search function
Movie* MovieInventory::search(int key)
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
		// 
		if(table[hash].key == 0)
		{
			cerr << "Movie not in Inventory" << endl;
			// put a break; once it works lol
		};
		if (table[hash].isClassic)
		{
			hash++;
			continue;
		}
		if (table[hash].movie->getGenre() == "F") // comedy
		{
			//string keyF = "F" + table[hash].movie->getReleaseYear() + table[hash].movie->getTitle();
			//int tempHash = hashFunction(Store::cstoi(keyF));
			if (table[hash].key == hash)
			{
				return table[hash].movie;
			}
		}
		else if (table[hash].movie->getGenre() == "D") // drama
		{
			//string keyD = "D" + table[hash].movie->getDirector() + table[hash].movie->getTitle();
			//int tempHash = hashFunction(Store::cstoi(keyD));
			if (table[hash].key == hash)
			{
				return table[hash].movie;
			}
		}
		//if the key wasn't the same as the id of the customer, it's the wrong
		//spot, so use linear probing to find it
		hash++;
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
	

	//if the while loop concludes without returning the proper customer
	Movie temp = Movie();
	Movie* tempPtr = &temp;
	cerr << "Error: could not find Movie with Key of '" <<
	key << "' default Movie was returned";
	return tempPtr;
}

Classic* MovieInventory::classicSearch(int key)
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
		
		if (!(table[hash].isClassic))
		{
			hash++;
			continue;
		}
		if (table[hash].classic->getGenre() == "C") // classics
		{
			//string keyC = "C" + table[hash].classic->getReleaseDate() + table[hash].classic->getActor();
			//int tempHash = hashFunction(Store::cstoi(keyC));
			if (hash == table[hash].key)
			{
				return table[hash].classic;
			}
		}
		//if the key wasn't the same as the id of the customer, it's the wrong
		//spot, so use linear probing to find it
		hash++;
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
	

	//if the while loop concludes without returning the proper customer
	Classic temp = Classic();
	Classic* tempPtr = &temp;
	cerr << "Error: could not find customer with ID of '" <<
	key << "' default customer of '0, first, last' was returned";
	return tempPtr;
}

//-----------------------------------------------------------------
//remove function
void MovieInventory::remove(int key)
{
	int hash = hashFunction(key);
	//make a copy of inital hash to keep constant for already visited check
	//int hashVisited = hash;
	bool good = true;

	while (hash < TABLE_SIZE)
	{
		if (table[hash].movie->getGenre() == "F") // comedy
		{
			//string keyF = "F" + table[hash].movie->getReleaseYear() + table[hash].movie->getTitle();
			//int tempHash = hashFunction(Store::cstoi(keyF));
			if (table[hash].key == key)
			{
				Movie temp = Movie();
				Movie* tempPtr = &temp;
				table[hash].movie = tempPtr;
				return;
			}
		}
		else if (table[hash].movie->getGenre() == "D") // drama
		{
			//string keyD = "D" + table[hash].movie->getDirector() + table[hash].movie->getTitle();
			//int tempHash = hashFunction(Store::cstoi(keyD));
			if (table[hash].key == key)
			{
				Movie temp = Movie();
				Movie* tempPtr = &temp;
				table[hash].movie = tempPtr;
				return;
			}
		}
		else if (table[hash].movie->getGenre() == "C") // clasic
		{
			//string keyC = "C" + table[hash].classic->getReleaseDate() + table[hash].classic->getActor();
			//int tempHash = hashFunction(Store::cstoi(keyC));
			if (table[hash].key == key)
			{
				Classic temp = Classic();
				Classic* tempPtr = &temp;
				table[hash].classic = tempPtr;
				return;
			}
		}
		//if the key wasn't the same as the id of the customer, it's the wrong
		//spot, so use linear probing to find it
		hash++;
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
	

	//if the while loop concludes without returning the proper customer
	
	cerr << "Error: could not find customer with ID of '" <<
	key << "' as such, no customer was removed";
	
}

