#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H
#include <string>

class Product {
private:
    std::string name_;
    float price_;
    int quantityDelivery_;
    int soldForMonth_;

public:
    Product();
    Product(std::string name, float price=0.0);
    Product(std::string name, float price, int quantityDelivery, int soldForMonth);
    ~Product();

    std::string getName();
    void setName(std::string);

    float getPrice();
    void setPrice(int);
    void setPrice(float);

    int getQuantityDelivery();
    void setQuantityDelivery(int);

    int getSoldForMonth();
    void setSoldForMonth(int);
};

#endif //UNTITLED_PRODUCT_H