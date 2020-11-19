#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
	firstname_ = "Name";
	surname_ = "Surname";
}

Person::Person(string name, string surname) {
	firstname_ = name;
	surname_ = surname;
}

Person::Person(string name, string surname, int year, int month, int day) : Date(year, month, day) {
	firstname_ = name;
	surname_ = surname;
}

Person::Person(string name, string surname, Date* date) : Date(date) {
	firstname_ = name;
	surname_ = surname;
}

Person::Person(string name, string surname, Date date) : Date(date) {
	firstname_ = name;
	surname_ = surname;
}

Person::Person(Person& person): Date(person.getDate()){
	firstname_ = person.firstname_;
	surname_ = person.surname_;
}

Person::Person(Person* person): Date(person->getDate()) {
	firstname_ = person->firstname_;
	surname_ = person->surname_;
}


string Person::getFirstname() {
	return firstname_;
}

void Person::setFirstname(string name) {
	firstname_ = name;
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