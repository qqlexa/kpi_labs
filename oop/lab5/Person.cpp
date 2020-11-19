#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
	name_ = "Name";
	surname_ = "Surname";
}

Person::Person(string name, string surname) {
	name_ = name;
	surname_ = surname;
}

Person::Person(string name, string surname, int year, int month, int day) : Date(year, month, day) {
	name_ = name;
	surname_ = surname;
}

Person::Person(string name, string surname, Date* date) : Date(date) {
	name_ = name;
	surname_ = surname;
}

Person::Person(string name, string surname, Date date) : Date(date) {
	name_ = name;
	surname_ = surname;
}

Person::Person(Person& person): Date(person.getDate()){
	name_ = person.name_;
	surname_ = person.surname_;
}

Person::Person(Person* person): Date(person->getDate()) {
	name_ = person->name_;
	surname_ = person->surname_;
}


string Person::getName() {
	return name_;
}

void Person::setName(string name) {
	name_ = name;
}

string Person::getSurname() {
	return surname_;
}

void Person::setSurname(string surname) {
	surname_ = surname;
}

Person& Person::getPerson() {
	return *this;
}