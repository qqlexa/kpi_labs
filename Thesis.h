#pragma once
#include <iostream>
#include "Date.h"
#include "AuthorStudent.h"
#include "AuthorBoss.h"

using namespace std;

class Thesis :
    virtual public Date,
    public AuthorStudent,
    public AuthorBoss
{
private:
    string name_;
    int countDraws_;
    int countLinks_;
    float amountLists_;
public:
    Thesis();
    Thesis(Date, AuthorStudent, AuthorBoss);
    Thesis(Date, AuthorStudent, AuthorBoss, string, int, int, float);

    Thesis(Thesis&);
    Thesis(Thesis*);

    string getName();
    void setName(string);

    int getCountDraws();
    void setCountDraws(int);

    int getCountLinks();
    void setCountLinks(int);

    float getAmountLists();
    void setAmountLists(float);

    Thesis& getThesis();
};

