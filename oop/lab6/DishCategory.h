#pragma once
#include <iostream>

enum class DishType {
	FIRST_COURSE,
	MAIN_COURSE,
	DESSERT,
};

class DishCategory {
protected:
	DishType dishType_;
public:
	DishCategory();
	DishCategory(DishType);

	DishType getDishType();
	void setDishType(DishType);

	virtual void show();
};