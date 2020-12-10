#include <iostream>

#include "Dish.h"

using namespace std;

Dish::Dish() {
	name_ = "Dish name";
	price_ = 0;
}

Dish::Dish(string name, float price, DishType dishType) : DishCategory(dishType){
	name_ = name;
	price_ = (price > 0) ? price : 0;
}

string Dish::getName() {
	return name_;
}

void Dish::setName(string name) {
	name_ = name;
}

float Dish::getPrice() {
	return price_;
}

void Dish::setPrice(float price) {
	price_ = (price > 0) ? price : 0;
}

void Dish::show() {
	cout << "name_: " << name_ << endl;
	cout << "price_: " << price_ << endl;
	DishCategory::show();
}