#pragma once
#include <iostream>
#include "Date.h"
#include "Author.h"
#include "Author2.h"

using namespace std;

class Thesis :
    public Date,
    public Author,
    public Author2
{
private:
    string name_;
    int countDraws_;
    int countLinks_;
    float amountLists_;
public:
    Thesis();
    Thesis(Date, Author, Author2);
    Thesis(Date, Author, Author2, string, int, int, int);
};

