#pragma once
#include <iostream>
#include <vector>

#include "Thesis.h"
#include "Date.h"

using namespace std;

class ThesisComposition :
    public Date
{
protected:
    vector<Thesis> thesisComposition_;
    int countLists_;
public:
    ThesisComposition();
    ThesisComposition(vector<Thesis>, 
        int, int, int,               // Date
        int countLists=0);

    ThesisComposition(ThesisComposition&);

    ~ThesisComposition();

    vector<Thesis> getComposition();
    void setComposition(vector<Thesis>);
    void appendComposition(Thesis);
    void clearComposition();

    int getCountLists();
    void setCountLists(int);

    void printCompositionInfo();
    virtual void show();
};

