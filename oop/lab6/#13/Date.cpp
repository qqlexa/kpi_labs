#include "Date.h"
#include <iostream>

using namespace std;


Date::Date() {
	year_ = 1970;
	month_ = 1;
	day_ = 1;
}

Date::Date(int year, int month, int day) {
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(Date& date) {
	year_ = date.year_;
	month_ = date.month_;
	day_ = date.day_;
}


int Date::getYear() {
	return year_;
}

void Date::setYear(int year) {
	year_ = (year > 0) ? year : 1970;
}

int Date::getMonth() {
	return month_;
}

void Date::setMonth(int month) {
	month_ = (month > 0 && month <= 12) ? month : 1;
}

int Date::getDay() {
	return day_;
}

void Date::setDay(int day) {
	int limitDay;
	switch (month_) {
	case 2:
		limitDay = (year_ % 4) ? 28 : 29;
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		limitDay = 31;
		break;
	case 4:
	case 6:
	case 11:
	default:
		limitDay = 30;
		break;
	}
	day_ = (day > 0 && day <= limitDay) ? day : 1;
}

void Date::setDate(int year, int month, int day) {
	setYear(year);
	setMonth(month);
	setDay(day);
}
