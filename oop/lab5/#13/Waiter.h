#pragma once
#include "Person.h"
#include "Category.h"
#include "Date.h"

class Waiter :
    public Person,
    public Category,
    virtual public Date
{
public:
    Waiter();
    Waiter(string, string, Sex, int, int, int, WorkCategory, int, int, int);
};

