#pragma once
#include "Date.h"
#include <iostream>

using namespace std;

class Person :
    public Date
{
private:
    string firstname_;
    string surname_;

public:
    Person();
    Person(string, string);
    Person(string, string, int, int, int);
    Person(string, string, Date);
    Person(string, string, Date*);

    Person(Person&);
    Person(Person*);

    string getFirstname();
    void setFirstname(string);


    string getSurname();
    void setSurname(string);

    Person& getPerson();
};

