#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Product* createEllipseByInput();
void tableOnScreen(vector<Product*>);


int main() {
    // demonstration of default-constructor
    Product product("Product 1");
    product.printFields();
    cout << endl << endl;

    // demonstration of copy-constructor
    Product product2(product + 30.0);
    cout << endl << endl;

    cout << product << endl;

    // demonstration of destructor
    Product* carrot = new Product("Carrot", 10);
    Product* pumpkin = new Product("Pumpkin", 10.5, 50, 20);

    // overloading operator float()
    cout << float(*carrot) << endl;

    // overloading condition operators
    cout << "Is price of carrot == pumpkin?: " << ((*carrot == *pumpkin) ? "Yes" : "No") << endl;
    cout << "Is price of carrot > pumpkin?: " << ((*carrot > * pumpkin) ? "Yes" : "No") << endl;
    cout << "Is price of carrot >= pumpkin?: " << ((*carrot >= *pumpkin) ? "Yes" : "No") << endl;
    cout << "Is price of carrot < pumpkin?: " << ((*carrot < *pumpkin) ? "Yes" : "No") << endl;
    cout << "Is price of carrot <= pumpkin?: " << ((*carrot <= *pumpkin) ? "Yes" : "No") << endl;

    delete carrot;
    delete pumpkin;
    cout << endl << endl;

    vector<Product*> products;
    string userInput = "";
    while (true) {
        cout <<
            "0) exit" << endl <<
            "1) add ellipse" << endl <<
            "2) print table" << endl <<
            "$ ";
        getline(cin, userInput);
        if (userInput == "0") {
            return 0;
        }
        else if (userInput == "1") {
            products.push_back(createEllipseByInput());
            cin.clear();
            cin.ignore();
        }
        else if (userInput == "2") {
            tableOnScreen(products);
        }
    }

    return 0;
}

Product* createEllipseByInput() {
    Product* localEllipse = new Product();
    string userInput;
    float floatVar = 0;
    float floatVar2 = 0;
    cout << "Enter product name: ";
    getline(cin, userInput);
    localEllipse->setName(userInput);
    cout << "Enter price (>=0): ";
    cin >> floatVar;
    localEllipse->setPrice(floatVar);
    cout << "Enter quantityDelivery (>=0): ";
    cin >> floatVar;
    localEllipse->setQuantityDelivery(floatVar);
    cout << "Enter soldForMonth (>=0): ";
    cin >> floatVar;
    localEllipse->setSoldForMonth(floatVar);
    cout << endl;
    return localEllipse;
}

void tableOnScreen(vector<Product*> products) {
    int n = products.size();

    cout << setw(20) << left << "Product name"
        << setw(20) << left << "price"
        << setw(20) << left << "quantityDelivery"
        << setw(20) << left << "soldForMonth"
        << endl;

    for (int i = 0; i < n; i++) {
        products[i]->printFields();
    }
}
