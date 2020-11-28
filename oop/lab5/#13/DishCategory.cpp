#pragma once
#include <iostream>

#include "DishCategory.h"

DishCategory::DishCategory() {
	dishType_ = DishType::FIRST_COURSE;
}

DishCategory::DishCategory(DishType dishType) {
	dishType_ = dishType;
}


DishType DishCategory::getDishType() {
	return dishType_;
}

void DishCategory::setDishType(DishType dishType) {
	dishType_ = dishType;
}