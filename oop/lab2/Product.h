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
    Product();                                                                       // default constructor
    Product(std::string name, float price=0.0);                                      // constructor with default parameter
    Product(std::string name, float price, int quantityDelivery, int soldForMonth);  // overload-constructor
    Product(std::string name, double price, int quantityDelivery, int soldForMonth); // overload-constructor
    Product(const Product&);                                                         // copy-constructor

    ~Product();                                                                      // destructor

    std::string getName();
    void setName(std::string);

    float getPrice();
    void setPrice(int);     // overloading of method
    void setPrice(float);   // overloading of method
    void setPrice(double);  // overloading of method
                            
    int getQuantityDelivery();
    void setQuantityDelivery(int);

    int getSoldForMonth();
    void setSoldForMonth(int);

    Product& operator++();
    Product operator++(int);

    Product& operator--();
    Product operator--(int);
};

#endif //UNTITLED_PRODUCT_H