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

void Category::show() {
	cout << "workCategory_: ";
	switch (workCategory_) {
	case WorkCategory::JUNIOR_WAITER: {
		cout << "JUNIOR_WAITER" << endl;
	} break;
	case WorkCategory::WAITER: {
		cout << "WAITER" << endl;
	} break;
	case WorkCategory::SENIOR_WAITER: {
		cout << "SENIOR_WAITER" << endl;
	} break;
	case WorkCategory::HEADWAITER: {
		cout << "HEADWAITER" << endl;
	} break;
	}
}