#ifndef CLASSIC_H
#define CLASSIC_H
#pragma once;
#include <iostream>

using namespace std;

class Classic
{
    public:
        string getActor();
        string getReleaseDate();

        int borrowMovie();
        int returnMovie();
    private:
        string actorFirst;
        string actorLast;
        int month;
        int totalStock;
};

#endif // CLASSIC_H