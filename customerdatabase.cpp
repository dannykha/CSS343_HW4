#include "customerdatabase.h"
#include <iostream> 

using namespace std;

CustomerDatabase::CustomerDatabase()
{
	table = new HashElementCust *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

CustomerDatabase::~CustomerDatabase()
{
	destroy();
}

void CustomerDatabase::destroy()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != nullptr)
		{
			delete table[i]->customer;
			delete table[i];
		}
	}
	delete[] table;
}

int CustomerDatabase::hashFunction(int key)
{
	int modVal = TABLE_SIZE - 1;
	return key % modVal;
}

void CustomerDatabase::insert(int key, Customer *custPtr)
{
	int hash = hashFunction(key);
	while (table[hash] != nullptr && table[hash]->key != key)
    {
        hash = hashFunction(hash + 1);
    }
	if (table[hash] != nullptr)
    {
        delete table[hash];
    }
	table[hash] = new HashElementCust(key, custPtr);
}

Customer* CustomerDatabase::search(int key)
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
        return table[hash]->customer;
    }
}

void CustomerDatabase::remove(int key)
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
