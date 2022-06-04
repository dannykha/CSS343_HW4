#include "movieinventory.h"
#include <iostream> 
#include <cmath>

using namespace std;

const int PRIME_CONST = 31;

MovieInventory::MovieInventory()
{
	table = new HashElement *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

MovieInventory::~MovieInventory()
{
	destroy();
}

void MovieInventory::destroy()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr)
		{
			delete table[i]->movie;
			delete table[i];
		}
	}
	delete[] table;
}

int MovieInventory::hashFunction(string key)
{
	int modVal = TABLE_SIZE - 1;
	for (int i = 0; i < key.length(); i++) {
        modVal += key[i] * pow(PRIME_CONST, i);
    }
    return modVal;
}

void MovieInventory::insert(Movie * moviPtr)
{
    string key = moviPtr->getGenre + moviPtr->getDirector + to_string(moviPtr->getReleaseYear) + moviPtr->getTitle;
	int hash = hashFunction(key);
	while (table[hash] != nullptr && table[hash]->key != key)
    {
        hash = hashFunction(hash + 1);
    }
	if (table[hash] != nullptr)
    {
        delete table[hash];
    }
	table[hash] = new HashElement(key, moviPtr);
}

Movie * MovieInventory::search(int key)
{
	int hash = hashFunction(key);
	while (table[hash] != nullptr && table[hash]->key != key)
    {
        hash = hashFunction(hash + 1);
    }
	if (table[hash] == nullptr)
    {
		return nullptr;
    }
	else
    {
        return table[hash]->movie;
    }
}

void MovieInventory::remove(int key)
{
	int hash = hashFunction(key);
	while (table[hash] != nullptr)
	{
		if (table[hash]->key == key)
        {
            break;
        }
		hash = hashFunction(hash + 1);
	}
	if (table[hash] == nullptr)
	{
		cout << "No Element found at key: " << key << endl;
		return;
	}
	else
    {
        delete table[hash];
    }
	cout << "Element Deleted" << endl; 
}