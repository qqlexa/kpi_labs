#include "Ellipse.h"
#include <math.h>
#include <string>
#include <iomanip>
#include <iostream>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

Ellipse::Ellipse() {
	std::string name = "Ellipse";
	nameLen_ = name.length();
	name_ = new char[nameLen_ + 1];
	for (int i = 0; i < name.length(); i++) {
		name_[i] = name[i];
	}

	x_ = 0.0;
	y_ = 0.0;

	radius1_ = 0;
	radius2_ = 0;
	square_ = 0.0;
	checkIntegrity();
}

Ellipse::Ellipse(char* name) {
	name_ = name;
	x_ = 0;
	y_ = 0;

	radius1_ = 0;
	radius2_ = 0;
	square_ = 0.0;
	checkIntegrity();
}

Ellipse::Ellipse(std::string name) {
	nameLen_ = name.length();
	name_ = new char[nameLen_ + 1];
	for (int i = 0; i < name.length(); i++) {
		name_[i] = name[i];
	}
	x_ = 0;
	y_ = 0;

	radius1_ = 0;
	radius2_ = 0;
	square_ = 0.0;
	checkIntegrity();
}

Ellipse::Ellipse(char* name, float x, float y, float radius1, float radius2) {
	name_ = name;
	x_ = x;
	y_ = y;

	radius1_ = radius1;
	radius2_ = radius2;
	square_ = 0.0;
	checkIntegrity();
}

Ellipse::Ellipse(std::string name, float x, float y, float radius1, float radius2) {
	nameLen_ = name.length();
	name_ = new char[nameLen_ + 1];
	for (int i = 0; i < name.length(); i++) {
		name_[i] = name[i];
	}
	x_ = x;
	y_ = y;

	radius1_ = radius1;
	radius2_ = radius2;
	square_ = 0.0;
	checkIntegrity();
}

Ellipse::Ellipse(char* name, float x, float y, float radius1, float radius2, float square) {
	name_ = name;
	x_ = x;
	y_ = y;

	radius1_ = radius1;
	radius2_ = radius2;
	square_ = square;
	checkIntegrity();
}

Ellipse::Ellipse(std::string name, float x, float y, float radius1, float radius2, float square) {
	nameLen_ = name.length();
	name_ = new char[nameLen_ + 1];
	for (int i = 0; i < name.length(); i++) {
		name_[i] = name[i];
	}
	x_ = x;
	y_ = y;

	radius1_ = radius1;
	radius2_ = radius2;
	square_ = square;
	checkIntegrity();
}

Ellipse::Ellipse(const Ellipse& ellipse) {
	std::cout << "Copy constructor" << std::endl;
	nameLen_ = ellipse.nameLen_;
	name_ = new char[nameLen_ + 1];
	for (int i = 0; i < nameLen_; i++) {
		name_[i] = ellipse.name_[i];
	}
	x_ = ellipse.x_;
	y_ = ellipse.y_;

	radius1_ = ellipse.radius1_;
	radius2_ = ellipse.radius2_;
	square_ = ellipse.square_;
	checkIntegrity();
}

Ellipse::~Ellipse() {
	delete[] name_;
	
}

void Ellipse::setName(std::string name) {
	delete[] name_;
	nameLen_ = name.length();
	name_ = new char[nameLen_ + 1];
	for (int i = 0; i < name.length(); i++) {
		name_[i] = name[i];
	}

	if (!checkName()) {
		exit(1); // throw exception would be better
	}
}

std::string Ellipse::getName() {
	return std::string(name_);
}

void Ellipse::printName() {
	for (int i = 0; i < nameLen_; i++) {
		std::cout << name_[i];
	}
	std::cout << std::endl;
}

void Ellipse::setRadiusses(float radius1, float radius2) {
	radius1_ = radius1;
	radius2_ = radius2;
	if (!checkRadiusses()) {
		exit(1); // throw exception would be better
	}
}

void Ellipse::setRadius1(float radius) {
	radius1_ = radius;
	if (!checkRadius1()) {
		exit(1); // throw exception would be better
	}
}

float Ellipse::getRadius1() {
	return radius1_;
}

void Ellipse::setRadius2(float radius) {
	radius2_ = radius;
	if (!checkRadius2()) {
		exit(1); // throw exception would be better
	}
}

float Ellipse::getRadius2() {
	return radius2_;
}

void Ellipse::printRadiusses() {
	std::cout << "Radius1 of " << name_ << " is " << radius1_ << std::endl;
	std::cout << "Radius2 of " << name_ << " is " << radius2_ << std::endl;
}

void Ellipse::setX(float x) {
	x_ = x;
	if (!checkX()) {
		exit(1); // throw exception would be better
	}
}

float Ellipse::getX() {
	return x_;
}

void Ellipse::printX() {
	std::cout << "X of " << name_ << " is " << x_ << std::endl;
}

void Ellipse::incX() {
	x_++;
}

void Ellipse::setY(float y) {
	y_ = y;
	if (!checkY()) {
		exit(1); // throw exception would be better
	}
}

float Ellipse::getY() {
	return y_;
}

void Ellipse::printY() {
	std::cout << "Y of " << name_ << " is " << y_ << std::endl;
}

void Ellipse::incY() {
	y_++;
}

void Ellipse::setCenter(float x, float y) {
	x_ = x;
	y_ = y;
}

void Ellipse::setSquare(float square) {
	square_ = square;
	if (!checkSquare()) {
		exit(1); // throw exception would be better
	}
}

float Ellipse::getSquare() {
	return square_;
}

void Ellipse::printSquare() {
	std::cout << "Square of " << name_ << " is " << square_ << std::endl;
}

float Ellipse::countSquare() {
	square_ = sqrt(pow((x_ - radius1_), 2) + pow((y_ - radius2_), 2));
	return square_;
}

void Ellipse::printFields() {
	using namespace std;
	for (int i = 0; i < nameLen_; i++) {
		std::cout << name_[i];
	}
	std::cout << setw(abs(20 - nameLen_)) << left << " ";
	std::cout << setw(20) << left << radius1_
		<< setw(20) << left << radius2_
		<< setw(20) << left << x_
		<< setw(20) << left << y_
		<< setw(20) << left << square_ 
		<< endl;
	
}


bool Ellipse::operator>(const Ellipse& ellipseObjPar) {
	return (square_ > ellipseObjPar.square_) ? true : false;
}

bool Ellipse::operator<(const Ellipse& ellipseObjPar) {
	return (square_ < ellipseObjPar.square_) ? true : false;
}

bool Ellipse::operator==(const Ellipse& ellipseObjPar) {
	return (square_ == ellipseObjPar.square_) ? true : false;
}

bool Ellipse::operator>=(const Ellipse& ellipseObjPar) {
	return (square_ >= ellipseObjPar.square_) ? true : false;
}

bool Ellipse::operator<=(const Ellipse& ellipseObjPar) {
	return (square_ <= ellipseObjPar.square_) ? true : false;
}

std::string Ellipse::operator+(const std::string& str) {
	std::string result = "";
	for (int i = 0; i < nameLen_; i++) {
		result += name_[i];
	}
	return result + str;
}

// Ôóíêö³ÿ íå º ìåòîäîì êëàñó:
std::string operator+(std::string str, Ellipse& customObj) {
	return str + customObj.getName();
}

bool Ellipse::checkName() {
	if (strlen(name_) < 1) {
		std::cout << "\nWrong name_ parameter. Should not be empty\n";
		return false;
	}
	return true;
}

bool Ellipse::checkRadiusses() {
	if (radius1_ < 0 || radius2_ < 0) {
		std::cout << "\nWrong radius1_ or/and radius2_ parameter(s). Should not be < 0\n";
		return false;
	}
	return true;
}

bool Ellipse::checkRadius1() {
	if (radius1_ < 0) {
		std::cout << "\nWrong radius1_ parameter. Should not be < 0\n";
		return false;
	}
	return true;
}

bool Ellipse::checkRadius2() {
	if (radius2_ < 0) {
		std::cout << "\nWrong radius2_ parameter. Should not be < 0\n";
		return false;
	}
	return true;
}

bool Ellipse::checkX() {
	return true;
}

bool Ellipse::checkY() {
	return true;
}

bool Ellipse::checkSquare() {
	if (square_ < 0) {
		std::cout << "\nWrong square_ parameter. Should not be < 0\n";
		return false;
	}
	return true;
}

void Ellipse::checkIntegrity() {
	if (!(checkName() && checkRadiusses() && checkX() && checkY() && checkSquare())) {
		exit(1); // throw exception would be better
	}
}
