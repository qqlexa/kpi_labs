#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H
#include <string>

class Product {
private:
    char* name_;
    float price_;
    int quantityDelivery_;
    int soldForMonth_;

public:
    Product();                                                                       // default constructor
    Product(std::string name, float price = 0.0);                                      // constructor with default parameter
    Product(std::string name, float price, int quantityDelivery, int soldForMonth);  // overload-constructor
    Product(std::string name, double price, int quantityDelivery, int soldForMonth); // overload-constructor
    Product(const Product&);                                                         // copy-constructor

    ~Product();                                                                      // destructor

    std::string getName();
    void setName(std::string);

    float getPrice();
    void setPrice(float);

    int getQuantityDelivery();
    void setQuantityDelivery(int);

    int getSoldForMonth();
    void setSoldForMonth(int);

    void riseInPrice(int);    // overloading
    void riseInPrice(float);  // overloading
    void riseInPrice(double); // overloading

    std::string operator+(const std::string&);

private:
    bool checkName();             // checks name_ is correct
    bool checkPrice();            // checks price_ is correct
    bool checkQuantityDelivery(); // checks quantityDelivery_ is correct
    bool checkSoldForMonth();     // checks soldForMonth_ is correct
    void checkIntegrity();        // checks everything
};

std::string operator+(std::string, Product&);

#endif //UNTITLED_PRODUCT_H
