#pragma once
#include <iostream>

#include "WorkCategory.h"

using namespace std;

class Category
{
private:
	WorkCategory workCategory_;
public:
	Category();
	Category(WorkCategory);

	~Category();


	WorkCategory getWorkCategory();
	void setWorkCategory(WorkCategory);
	
	virtual void show();
};

