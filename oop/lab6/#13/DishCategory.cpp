#pragma once
#include <iostream>

#include "DishCategory.h"

using namespace std;

DishCategory::DishCategory() {
	dishType_ = DishType::FIRST_COURSE;
}

DishCategory::DishCategory(DishType dishType) {
	dishType_ = dishType;
}

DishCategory::~DishCategory() {
	show();
}

DishType DishCategory::getDishType() {
	return dishType_;
}

void DishCategory::setDishType(DishType dishType) {
	dishType_ = dishType;
}

void DishCategory::show() {
	cout << "DishCategory.show()" << endl;
}