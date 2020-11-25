#pragma once
#include <iostream>

#include "Date.h"
#include "Author.h"

using namespace std;

class Thesis :
    virtual public Date
{
protected:
    Author authorStudent_;
    Author authorBoss_;
    string drawName_;
    int countDraws_;
    int countLinks_;
    float amountLists_;
public:
    Thesis();
    Thesis(int, int, int,                       // Date
        string, string, int, int, int, Post,    // AuthorStudent
        string, string, int, int, int, Post,    // AuthorBoss 
        string, int, int, float);               // name, countDraws, countLinks, amountLists

    Thesis(Thesis&);
    Thesis(Thesis*);

    Thesis(const Thesis&);
    Thesis(const Thesis*);

    Author& getAuthorStudent();
    void setAuthorStudent(Author&);

    Author& getAuthorBoss();
    void setAuthorBoss(Author&);

    string getDrawName();
    void setDrawName(string);

    int getCountDraws();
    void setCountDraws(int);

    int getCountLinks();
    void setCountLinks(int);

    float getAmountLists();
    void setAmountLists(float);
};

