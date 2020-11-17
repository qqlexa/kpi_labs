#pragma once
#include "Date.h"
#include <iostream>

using namespace std;

class Person :
    public Date
{
private:
    string name_;
    string surname_;

public:
    Person();
    Person(string, string);
    Person(string, string, int, int, int);

    string getName();
    void setName(string);


    string getSurname();
    void setSurname(string);
};

