#include <iostream>
#include "ThesisComposition.h"
#include <vector>

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

    aTeacher.setPost(Post::ASSISTANT);
    Thesis thesis2(today, aMe, aTeacher);

    aTeacher.setPost(Post::DOCENT);
    Thesis thesis3(today, aMe, aTeacher);

    vector<Thesis> compositions = {thesis1, thesis2, thesis3};

    ThesisComposition thesisComposition(compositions, today);
    
    return 0;
}
