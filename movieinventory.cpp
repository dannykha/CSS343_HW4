#include "movieinventory.h"


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

void MovieInventory::insert(Movie *moviPtr)
{
	string temp;
	if (moviPtr->getGenre() == "F") // Comedy
	{
		temp = moviPtr->getGenre() + to_string(moviPtr->getReleaseYear()) + moviPtr->getTitle();
	}
	else if (moviPtr->getGenre() == "D") // Drama
	{
		temp = moviPtr->getGenre() + moviPtr->getDirector() + moviPtr->getTitle();
	}

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

void MovieInventory::insert(Classic *classicPtr) // Classic
{
	string temp;
	temp = classicPtr->getGenre() + classicPtr->getReleaseDate() + classicPtr->getActor();
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
	table[hash] = new HashElement(key, classicPtr);
}

Movie* MovieInventory::search(int key)
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

void MovieInventory::printInventory()
{
	// sortMovies();
	for (long unsigned int i = 0; i < vecMovie.size(); i++)
	{
		
		cout << "Printing the inventory...";
		cout << "Title	Genre	Stock	Year	Director";
		cout << vecMovie.at(i).getTitle() << " ";
		cout << vecMovie.at(i).getGenre() << " ";
		cout << vecMovie.at(i).getStock() << " ";
		cout << vecMovie.at(i).getReleaseYear() << " ";
		cout << vecMovie.at(i).getDirector() << " ";
		cout << endl;
	}
}

// void MovieInventory::sortMovies()
// {
// 	numComedy = 0;
// 	numDrama = 0;
// 	numClassic = 0;
// 	for (auto i = 0; i < TABLE_SIZE; i++) 
// 	{
// 		if (table[i]->movie->getGenre() == "C")
// 		{
// 			numClassic += 1;
// 		}
// 		else if (table[i]->movie->getGenre() == "F")
// 		{
// 			numComedy += 1;
// 		}
// 		else if (table[i]->movie->getGenre() == "D")
// 		{
// 			numDrama += 1;
// 		}
// 		vecMovie.push_back(*table[i]->movie);
// 	}
// 	sort(vecMovie.begin(), vecMovie.end(), compareGenre);
// 	sort(vecMovie.begin(), vecMovie.begin() + numComedy, compareTitle);
// 	// iterator through the comdey, use two pointers, 
// 	// if the first pointer and the second pointer equal the same title, 
// 	// then swap those based on year released
// 	int itr1 = 0;
// 	int itr2 = 0;
// 	// For comedy
// 	for (int j = 0; j < numComedy; j++)
// 	{
// 		itr2++;
// 		j = itr2;
// 		if (vecMovie.size() > 1 && vecMovie.at(itr1).getTitle() == vecMovie.at(itr2).getTitle())
// 		{
// 			sort(vecMovie.begin() + itr1, vecMovie.begin() + itr2, compareComedyYear);
// 		}
// 		itr1++;
// 	}

// 	// For drama
// 	sort(vecMovie.begin() + numComedy, vecMovie.begin() + numDrama, compareDramaDirector);
// 	itr1 = numComedy;
// 	itr2 = numComedy;
// 	for (int k = numComedy; k <= numComedy + numDrama; k++)
// 	{
// 		itr2++;
// 		k = itr2;
// 		if (vecMovie.size() > 1 && vecMovie.at(itr1).getTitle() == vecMovie.at(itr2).getTitle())
// 		{
// 			sort(vecMovie.begin() + itr1, vecMovie.begin() + itr2, compareTitle);
// 		}
// 		itr1++;
// 	}

// 	// For classic
// 	sort(vecMovie.begin() + numComedy + numDrama, vecMovie.end(), compareClassicRelease);
// 	itr1 = numComedy + numDrama;
// 	itr2 = numComedy + numDrama;
// 	for (int l = numComedy; l <= numComedy + numDrama; l++)
// 	{
// 		itr2++;
// 		l = itr2;
// 		if (vecMovie.size() > 1 && vecMovie.at(itr1).getTitle() == vecMovie.at(itr2).getTitle())
// 		{
// 			sort(vecMovie.begin() + itr1, vecMovie.begin() + itr2, compareClassicActor);
// 		}
// 		itr1++;
// 	}
// }

// bool MovieInventory::compareGenre(Movie m1, Movie m2)
// {
// 	return (m1.getGenre() < m2.getGenre());
// }

// bool MovieInventory::compareTitle(Movie m1, Movie m2)
// {
// 	return (m1.getTitle() < m2.getTitle());
// }

// bool MovieInventory::compareComedyYear(Movie m1, Movie m2)
// {
// 	return (m1.getReleaseYear() < m2.getReleaseYear());
// }

// bool MovieInventory::compareDramaDirector(Movie m1, Movie m2)
// {
// 	return (m1.getDirector() < m2.getDirector());
// }

// bool MovieInventory::compareClassicRelease(Classic m1, Classic m2)
// {
// 	return (m1.getReleaseDate() < m2.getReleaseDate());
// }

// bool MovieInventory::compareClassicActor(Classic m1, Classic m2)
// {
// 	return (m1.getActor() < m2.getActor());
// }