#include <iostream>
#include <vector>

#include "Thesis.h"
#include "ThesisComposition.h"

using namespace std;


int main() {

    Thesis thesis1;
    thesis1.setDrawName("Cool thesis!");
    Thesis thesis2(thesis1);

    // Раннє зв'язування
    thesis2.show();
    cout << endl;

    // Пізнє зв'язування
    Date* obj = &thesis2;
    obj->show();
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    Thesis thesis3(1, 1, 2000,
        "Name1", "SurName1", 2, 1, 2000, Post::STUDENT,
        "Name2", "SurName2", 3, 1, 2000, Post::MASTER,
        "DrawName3", 2, 3, 7.5);

    vector<Thesis> compositions = { thesis1, thesis2, thesis3 };

    ThesisComposition thesisComposition(compositions, 12, 12, 2012);
    thesisComposition.printCompositionInfo();

    cout << "Show()" << endl;
    thesisComposition.show();
    return 0;
}
