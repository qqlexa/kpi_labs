#pragma once
#include <iostream>

#include "Date.h"

using namespace std;

class Person :
    virtual public Date
{
protected:
    string firstName_;
    string secondName_;

public:
    Person();
    Person(string, string, int, int, int);

    Person(Person&);
    ~Person();

    string getFirstName();
    void setFirstName(string);


    string getSecondName();
    void setSecondName(string);

    virtual void show();
};

