#pragma once
#include <vector>
#include <iostream>

#include "Date.h"
#include "Waiter.h"
#include "Dish.h"

class Order :
    virtual public Date,
    public Waiter
{
protected:
        vector<Dish> dishList_;
public:
    Order();
    Order(vector<Dish>,
        int, int, int,               // Date
        std::string, std::string, Sex,
        WorkCategory);

    Order(Order&);

    vector<Dish> getDishList();
    void setDishList(vector<Dish>);
    void appendDishList(Dish);
    void clearDishList();

    void printDishListInfo();
    virtual void show();
};

