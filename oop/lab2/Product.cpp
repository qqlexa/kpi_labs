#include <iostream>
#include <string>
#include "Product.h"

Product::Product() {
    name_ = "Product";
    price_ = 0.0;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
    checkIntegrity();
}

Product::Product(std::string name, float price) {
    name_ = name;
    price_ = price;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
    checkIntegrity();
}

Product::Product(std::string name, float price, int quantityDelivery, int soldForMonth) {
    name_ = name;
    price_ = price;
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
    checkIntegrity();
}

Product::Product(std::string name, double price, int quantityDelivery, int soldForMonth) {
    name_ = name;
    price_ = float(price);
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
    checkIntegrity();
}

Product::Product(const Product& product) {
    name_ = product.name_;
    price_ = product.price_;
    quantityDelivery_ = product.quantityDelivery_;
    soldForMonth_ = product.soldForMonth_;
    std::cout << name_ << " was copied" << std::endl;
    checkIntegrity();
}

Product::~Product() {
    std::cout << "Destructor of " << name_ << std::endl;
}

std::string Product::getName() {
    return name_;
}

void Product::setName(std::string name) {
    name_ = name;
    if (!checkName()) {
        exit(1); // throw exception would be better
    }
}

float Product::getPrice() {
    return price_;
}

void Product::setPrice(float price) {
    price_ = price;
    if (!checkPrice()) {
        exit(1); // throw exception would be better
    }
}

int Product::getQuantityDelivery() {
    return quantityDelivery_;
}

void Product::setQuantityDelivery(int quantityDelivery) {
    quantityDelivery_ = quantityDelivery;
    if (!checkQuantityDelivery()) {
        exit(1); // throw exception would be better
    }
}

int Product::getSoldForMonth() {
    return soldForMonth_;
}

void Product::setSoldForMonth(int soldForMonth) {
    soldForMonth_ = soldForMonth;
    if (!checkSoldForMonth()) {
        exit(1); // throw exception would be better
    }
}

void Product::riseInPrice(int increase) {
    price_ += increase;
    if (!checkPrice()) {
        exit(1); // throw exception would be better
    }
}

void Product::riseInPrice(float increase) {
    price_ += increase;
    if (!checkPrice()) {
        exit(1); // throw exception would be better
    }
}

void Product::riseInPrice(double increase) {
    price_ += float(increase);
    if (!checkPrice()) {
        exit(1); // throw exception would be better
    }
}

std::string Product::operator+(const std::string& str) {
    return name_ + str;
}

std::string operator+(std::string str, Product& customObj) {
    return str + customObj.getName();
}

// value checks
bool Product::checkName() {
    if (name_.length() < 1) {
        std::cout << "\nWrong name_ parameter. Should not be empty\n";
        return false;
    }
    return true;
}

bool Product::checkPrice() {
    if (price_ < 0) {
        std::cout << "\nWrong price_ parameter. Should not be < 0\n";
        return false;
    }
    return true;
}

bool Product::checkQuantityDelivery() {
    if (quantityDelivery_ < 0) {
        std::cout << "\nWrong quantityDelivery_ parameter. Should not be < 0\n";
        return false;
    }
    return true;
}

bool Product::checkSoldForMonth() {
    if (soldForMonth_ < 0) {
        std::cout << "\nWrong soldForMonth_ parameter. Should not be < 0\n";
        return false;
    }
    return true;
}

void Product::checkIntegrity() {
    if (!(checkName() && checkPrice() && checkQuantityDelivery() && checkSoldForMonth())) {
        exit(1); // throw exception would be better
    }
}
