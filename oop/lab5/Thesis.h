#pragma once
#include <iostream>
#include "Date.h"
#include "Author.h"

using namespace std;

class Thesis :
    public Date,
    public Author
{
private:
    string name_;
    int countDraws_;
    int countLinks_;
    float amountLists_;
public:
    Thesis();
    Thesis(Date, Author);
    Thesis(Date, Author, string, int, int, int);
};

