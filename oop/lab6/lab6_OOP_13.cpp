#include <iostream>
#include <vector>

#include "Order.h"

using namespace std;


int main() {
    Dish potato;
    potato.setName("Potato!");
    potato.setPrice(2);

    Dish potato2(potato);
    potato2.setPrice(5);

    Dish carrot("Carrot", 10.5, DishType::MAIN_COURSE);

    vector<Dish> dishList = { potato, potato2, carrot };

    Order order(dishList, 12, 12, 2012, "Denis", "Rat", Sex::MALE, WorkCategory::HEADWAITER);
    order.printDishListInfo();

    cout << "Show()" << endl;
    order.show();
    return 0;
}
