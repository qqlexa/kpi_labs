#pragma once
#include <iostream>
#include "DishCategory.h"

using namespace std;

class Dish :
    public DishCategory
{
protected:
    string name_;
    float price_;
public:
    Dish();
    Dish(string, float, DishType);


    string getName();
    void setName(string);

    float getPrice();
    void setPrice(float);
};

