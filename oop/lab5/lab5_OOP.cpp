#include <iostream>
#include "Date.h"
#include "Person.h"

using namespace std;


int main(){
    Date today;
    today.setDay(3);

    Person me("Alex", "Hlavatsiy");
    cout << me.getDay() << endl;

    return 0;
}
