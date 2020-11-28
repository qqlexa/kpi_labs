#pragma once
#include <iostream>

#include "Date.h"
#include "Sex.h"

using namespace std;

class Person :
    virtual public Date
{
protected:
    string firstName_;
    string secondName_;
    Sex personSex_;

public:
    Person();
    Person(string, string, Sex, int, int, int);

    Person(Person&);
    Person(Person*);

    string getFirstName();
    void setFirstName(string);


    string getSecondName();
    void setSecondName(string);

    Sex getPersonSex();
    void setPersonSex(Sex);

};

