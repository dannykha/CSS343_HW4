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

int MovieInventory::hashFunction(int key)
{
	int modVal = TABLE_SIZE - 1;
    return key % modVal;
}

void MovieInventory::insert(Movie * moviPtr)
{
    string temp = moviPtr->getGenre() + moviPtr->getDirector() + to_string(moviPtr->getReleaseYear()) + moviPtr->getTitle();
	int key = stoi(temp);
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

void printInventory()
{

}

void sortMovies()
{
	numComedy = 0;
	numDrama = 0;
	numClassic = 0;
	for (auto i = 0; i < TABLE_SIZE; i++) 
	{
		if (table[i].getGenre() == "C")
		{
			numClassic += 1;
		}
		else if (table[i].getGenre() == "F")
		{
			numComedy += 1;
		}
		else if (table[i].getGenre() == "D")
		{
			numDrama += 1;
		}
		vecMovie.push_back(table[i]);
	}
	vecMovie.sort(vecMovie.begin(), vecMovie.end(), compareGenre);
	vecMovie.sort(vecMovie.begin(), numComedy, compareTitle);
	// iterator through the comdey, use two pointers, 
	// if the first pointer and the second pointer equal the same title, 
	// then swap those based on year released
}

bool MovieInventory::compareGenre(Movie m1, Movie m2)
{
	return (m1.getGenre() < m2.getGenre());
}

bool MovieInventory::compareTitle(Movie m1, Movie m2)
{
	return (m1.getTitle() < m2.getTitle());
}

bool MovieInventory::compareComedyYear(Movie m1, Movie m2)
{
	return (m1.getReleaseYear() < m2.getReleaseYear());
}

bool MovieInventory::compareDramaDirector(Movie m1, Movie m2)
{
	return (m1.getDirector() < m2.getDirector());
}

bool MovieInventory::compareClassicRelease(Classic m1, Classic m2)
{
	return (m1.getReleaseDate() < m2.getReleaseDate());
}

bool MovieInventory::compareClassicActor(Classic m1, Classic m2)
{
	return (m1.getActor() < m2.getActor());
}