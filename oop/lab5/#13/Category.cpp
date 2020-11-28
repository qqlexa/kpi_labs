#include "Category.h"
#include <iostream>

using namespace std;

Category::Category() {
	workCategory_ = WorkCategory::JUNIOR_WAITER;
}

Category::Category(WorkCategory workCategory) {
	workCategory_ = workCategory;
}

WorkCategory Category::getWorkCategory() {
	return workCategory_;
}

void Category::setWorkCategory(WorkCategory workCategory) {
	workCategory_ = workCategory;
}