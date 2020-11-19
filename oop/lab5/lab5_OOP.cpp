#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Author.h"

using namespace std;


int main(){
    Date* today = new Date();
    today->setDay(2);
    Date* tomorrow = new Date(today);
    Date tomorrow2(today);

    std::cout << "Today is " << today->getDay() << "." << today->getMonth() << "." << today->getYear() << endl;
    std::cout << "Tomorrow is " << tomorrow->getDay() << "." << tomorrow->getMonth() << "." << tomorrow->getYear() << endl;
    std::cout << "Tomorrow2 is " << tomorrow2.getDay() << "." << tomorrow2.getMonth() << "." << tomorrow2.getYear() << endl;

    Person me("Alex", "Hlav", today);
    std::cout << "I was born in " << me.getDay() << "." << me.getMonth() << "." << me.getYear() << endl;

    Person he(me);
    std::cout << "He was born in " << he.getDay() << "." << he.getMonth() << "." << he.getYear() << endl;
    
    Author writer();

    return 0;
}
