#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

void printProducts(vector<Product*> products) {
	char symbol = '#';
	cout << symbol <<
		setw(15) << " Class name" << setw(2) << symbol <<
		setw(8) << " Price" << setw(7) << symbol <<
		setw(16) << " Quantity delivery" << setw(2) << symbol <<
		setw(10) << " Sold for month" << setw(7) << symbol <<
		endl;
	for (int i = 0; i < 75; i++) {
		printf("%c", symbol);
	}
	cout << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << symbol << 
			setw(15) << (*products[i]).getName() << setw(2) << symbol <<
			setw(8) << (*products[i]).getPrice() << setw(7) << symbol <<
			setw(10) << (*products[i]).getQuantityDelivery() << setw(10) << symbol <<
			setw(10) << (*products[i]).getSoldForMonth() << setw(12) << symbol <<
			endl;
	}
	for (int i = 0; i < 75; i++) {
		printf("%c", symbol);
	}
	cout << endl;
}


int main() {
	Product* product = new Product();					     // name="Product", price=0, quantityDelivery=0, soldForMonth=0
	Product* carrot = new Product("Carrot");                 // price=0, quantityDelivery=0, soldForMonth=0
	Product* pumpkin = new Product("Pumpkin", 10.5, 50, 20);
	vector<Product*> products = { product, carrot, pumpkin };

	printProducts(products);

	// demonstration of copy-constructor
	Product cucumber("Cucumber", 15.8, 7500, 23);
	Product cucumber2(cucumber + "2");
	Product cucumber3("3" + cucumber);
	cout << endl;

	// demonstration of destructor
	delete product;                              
	delete carrot;                                 
	delete pumpkin;                                
	cout << endl;

	// demonstration of overloading
	cout << "The price of " << cucumber.getName() << " is rising!" << endl;
	cout << cucumber.getName() << " costs: " << cucumber.getPrice() << endl;
	cucumber.riseInPrice(10.2);
	cout << cucumber.getName() << " costs: " << cucumber.getPrice() << endl;
	cout << endl;
	return 0;
}