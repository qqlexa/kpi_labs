#include <iostream>
#include <string>
#include "Product.h"

Product::Product() {
    name_ = "Product";
    price_ = 0.0;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
}

Product::Product(std::string name, float price) {
    name_ = name;
    price_ = price;
    quantityDelivery_ = 0;
    soldForMonth_ = 0;
}

Product::Product(std::string name, float price, int quantityDelivery, int soldForMonth){
    name_ = name;
    price_ = price;
    quantityDelivery_ = quantityDelivery;
    soldForMonth_ = soldForMonth;
}

Product::~Product() {
    std::cout << "Destructor of " << name_ << std::endl;
}

std::string Product::getName() {
    return name_;
}

void Product::setName(std::string name) {
    name_ = name;
}

float Product::getPrice() {
    return price_;
}

void Product::setPrice(int price) {
    price_ = float(price);
}

void Product::setPrice(float price) {
    price_ = price;
}

int Product::getQuantityDelivery() {
    return quantityDelivery_;
}

void Product::setQuantityDelivery(int quantityDelivery) {
    quantityDelivery_ = quantityDelivery;
}

int Product::getSoldForMonth() {
    return soldForMonth_;
}

void Product::setSoldForMonth(int soldForMonth) {
    soldForMonth_ = soldForMonth;
}