#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
	firstName_ = "Name";
	secondName_ = "SecondName";
}

Person::Person(string name, string secondName, int year, int month, int day) : Date(year, month, day) {
	firstName_ = name;
	secondName_ = secondName;
}

Person::Person(Person& person){
	firstName_ = person.firstName_;
	secondName_ = person.secondName_;
}

Person::Person(Person* person){
	firstName_ = person->firstName_;
	secondName_ = person->secondName_;
}


string Person::getFirstName() {
	return firstName_;
}

void Person::setFirstName(string name) {
	firstName_ = name;
}

string Person::getSecondName() {
	return secondName_;
}

void Person::setSecondName(string secondName) {
	secondName_ = secondName;
}
