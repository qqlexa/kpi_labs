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
		setw(8) << " Price" << setw(2) << symbol <<
		setw(16) << " Quantity delivery" << setw(2) << symbol <<
		setw(10) << " Sold for month" << setw(7) << symbol <<
		endl;
	for (int i = 0; i < 70; i++) {
		printf("%c", symbol);
	}
	cout << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << symbol << 
			setw(15) << (*products[i]).getName() << setw(2) << symbol <<
			setw(8) << (*products[i]).getPrice() << setw(2) << symbol <<
			setw(10) << (*products[i]).getQuantityDelivery() << setw(10) << symbol <<
			setw(10) << (*products[i]).getSoldForMonth() << setw(12) << symbol <<
			endl;
	}
	for (int i = 0; i < 70; i++) {
		printf("%c", symbol);
	}
	cout << endl;
}


int main() {
	Product* product1 = new Product("Potato", 552.0);
	Product* product2 = new Product("Carrot", 5.5);
	Product* product3 = new Product("Pumpkin", 10.0, 7521, 23);
	vector<Product*> products = { product1, product2, product3 };

	printProducts(products);

	Product product4("Cucumber", 10.0, 7521, 23);

	delete product1;
	delete product2;
	delete product3;

	cout << "End the program" << endl;
	return 0;
}