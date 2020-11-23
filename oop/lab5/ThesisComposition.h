#pragma once
#include <iostream>
#include <vector>
#include "Thesis.h"
#include "Date.h"

using namespace std;

class ThesisComposition :
    public Date
{
private:
    vector<Thesis> composition_;
    int countLists_;
public:
    ThesisComposition();
    ThesisComposition(vector<Thesis>, Date, int countLists=0);

    ThesisComposition(ThesisComposition&);
    ThesisComposition(ThesisComposition*);

    vector<Thesis> getComposition();
    void setComposition(vector<Thesis>);
    void appendComposition(Thesis);
    void clearComposition();

    int getCountLists();
    void setCountLists(int);
};

