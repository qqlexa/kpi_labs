#include <iostream>

#include "Order.h"

using namespace std;

Order::Order() {
}

Order::Order(vector<Dish> dishList, 
	int year, int month, int day,  
	string name, string surname, Sex sex, 
	WorkCategory workCategory) : Waiter(name, surname, sex, year, month, day, workCategory, year, month, day), 
								 Date(year, month, day) {
	setDishList(dishList);
}


vector<Dish> Order::getDishList() {
	return dishList_;
}

void Order::setDishList(vector<Dish> composition) {
	dishList_.clear();
	for (Dish thesis : composition) {
		dishList_.push_back(thesis);
	}
}

void Order::appendDishList(Dish thesis) {
	dishList_.push_back(thesis);
}

void Order::clearDishList() {
	dishList_.clear();
}


void Order::printDishListInfo() {
	cout << "Waiter firstname: " << getFirstName() << endl;
	cout << "Waiter secondname: " << getSecondName() << endl;
	for (Dish dish : dishList_) {
		cout << "Dish name: " << dish.getName() << endl;
		cout << "Price: " << dish.getPrice() << endl;
		cout << endl;
	}
}

void Order::show() {
	for (Dish dish: dishList_) {
		dish.show();
	}
	Waiter::show();
	Date::show();
}