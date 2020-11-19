#include <iostream>
#include "Author.h"

using namespace std;


int main(){
    Date today;
    today.setDay(3);

    Author me("Alex", "Hlavatsiy", Post::STUDENT);
    cout << me.getDay() << endl;



    return 0;
}
