#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Author.h"
#include "Thesis.h"

using namespace std;


int main() {
    Date today;
    Person me("Alexey", "Hlavatskiy");
    Person teacher("Anton", "Kasyanov");

    Author aMe(me, Post::STUDENT);
    Author aTeacher(me, Post::TEACHER);

    Thesis thesis1(today, aMe, aTeacher);
    cout << 
        thesis1.getCountDraws() << endl <<
        thesis1.getCountLinks() << endl << 
        thesis1.getAmountLists() << endl;

    return 0;
}
