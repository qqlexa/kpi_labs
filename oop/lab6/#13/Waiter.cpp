#include "Waiter.h"

Waiter::Waiter() {

}

Waiter::Waiter(string name, string surname, Sex sex, int year, int month, int day, WorkCategory category, int enrollmentYear, int enrollmentMonth, int enrollmentDay) :
																										Person(name, surname, sex, year, month, day),
																										Category(category),
																										Date(enrollmentYear, enrollmentMonth, enrollmentDay)																									    
{

}

Waiter::~Waiter() {
	show();
}

void Waiter::show() {
	cout << "Waiter.show()" << endl;
}