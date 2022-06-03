#include "HashTable.h"
#include <iostream> 

using namespace std;

HashTable::HashTable()
{
	table = new HashElement *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

HashTable::~HashTable()
{
	destroy();
}

void HashTable::destroy()
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

int HashTable::hashFunction(int key)
{
	int modVal = TABLE_SIZE - 1;
	return key % modVal;
}

void HashTable::insert(int key, Customer * custPtr)
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
	table[hash] = new HashElement(key, custPtr);
}

Customer * HashTable::search(int key)
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

void HashTable::remove(int key)
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