#include <iostream>
#include <string>
#include <iomanip>
#include "Product.h"

Product::Product() {
    std::string name = "Product";
    nameLen_ = name.length();
    name_ = new char[nameLen_ + 1];
    for (int i = 0; i < name.length(); i++) {
        name_[i] = name[i];
    }
    price_ = 0.0;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
    checkIntegrity();
}

Product::Product(char* name, float price) {
    name_ = name;
    price_ = price;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
    checkIntegrity();
}

Product::Product(std::string name, float price) {
    nameLen_ = name.length();
    name_ = new char[nameLen_ + 1];
    for (int i = 0; i < nameLen_; i++) {
        name_[i] = name[i];
    }
    price_ = price;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
    checkIntegrity();
}

Product::Product(char* name, float price, int quantityDelivery, int soldForMonth) {
    name_ = name;
    price_ = float(price);
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
    checkIntegrity();
}

Product::Product(std::string name, float price, int quantityDelivery, int soldForMonth) {
    nameLen_ = name.length();
    name_ = new char[nameLen_ + 1];
    for (int i = 0; i < nameLen_; i++) {
        name_[i] = name[i];
    }
    price_ = price;
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
    checkIntegrity();
}

Product::Product(char* name, double price, int quantityDelivery, int soldForMonth) {
    name_ = name;
    price_ = float(price);
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
    checkIntegrity();
}

Product::Product(std::string name, double price, int quantityDelivery, int soldForMonth) {
    nameLen_ = name.length();
    name_ = new char[nameLen_ + 1];
    for (int i = 0; i < nameLen_; i++) {
        name_[i] = name[i];
    }
    price_ = float(price);
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
    checkIntegrity();
}

Product::Product(const Product& product) {
    std::cout << "Copy constructor" << std::endl;
    nameLen_ = product.nameLen_;
    name_ = new char[nameLen_ + 1];
    for (int i = 0; i < nameLen_; i++) {
        name_[i] = product.name_[i];
    }
    price_ = product.price_;
    quantityDelivery_ = product.quantityDelivery_;
    soldForMonth_ = product.soldForMonth_;
    checkIntegrity();
}

Product::~Product() {
    delete[] name_;
}

std::string Product::getName() {
    return name_;
}

void Product::setName(std::string name) {
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


bool Product::operator>(const Product& ellipseObjPar) {
    return (price_ > ellipseObjPar.price_) ? true : false;
}

bool Product::operator<(const Product& ellipseObjPar) {
    return (price_ < ellipseObjPar.price_) ? true : false;
}

bool Product::operator==(const Product& ellipseObjPar) {
    return (price_ == ellipseObjPar.price_) ? true : false;
}

bool Product::operator>=(const Product& ellipseObjPar) {
    return (price_ >= ellipseObjPar.price_) ? true : false;
}

bool Product::operator<=(const Product& ellipseObjPar) {
    return (price_ <= ellipseObjPar.price_) ? true : false;
}

std::string Product::operator+(const std::string& str) {
    std::string result = "";
    for (int i = 0; i < nameLen_; i++) {
        result += name_[i];
    }
    return result + str;
}


// Функція не є методом класу:
std::string operator+(std::string str, Product& customObj) {
    return str + customObj.getName();
}

Product::operator float() {
    return price_;
}

void Product::printFields() {
    using namespace std;
    for (int i = 0; i < nameLen_; i++) {
        std::cout << name_[i];
    }
    std::cout << setw(abs(20 - nameLen_)) << left << " ";
    std::cout << setw(20) << left << price_
        << setw(20) << left << quantityDelivery_
        << setw(20) << left << soldForMonth_
        << endl;

}

// value checks
bool Product::checkName() {
    if (strlen(name_) < 1) {
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