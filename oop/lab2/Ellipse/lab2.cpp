#include <iostream>
#include <iomanip>
#include <string>
#include "Ellipse.h"
#include <vector>

using namespace std;

Ellipse* createEllipseByInput();
void tableOnScreen(vector<Ellipse*>);

int main(){
    vector<Ellipse*> ellipses;
    Ellipse bigEllips;
    bigEllips.printFields();
    bigEllips.setName(bigEllips + "1");
    bigEllips.printFields();
    cout << endl << endl;

    string userInput = "";
    ellipses.push_back(new Ellipse("First"));
    ellipses.push_back(new Ellipse("Second", 3, 5));
    tableOnScreen(ellipses);
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
            ellipses.push_back(createEllipseByInput());
            cin.clear();
            cin.ignore();
        }
        else if (userInput == "2") {
            tableOnScreen(ellipses);
        }
    }

    return 0;
}

Ellipse* createEllipseByInput() {
    Ellipse* localEllipse = new Ellipse();
    string userInput = "";
    float floatVar = 0;
    float floatVar2 = 0;
    cout << "Enter ellipse name: ";
    getline(cin, userInput);
    localEllipse->setName(userInput);
    cout << "Enter x: ";
    cin >> floatVar;
    localEllipse->setX(floatVar);
    cout << "Enter y: ";
    cin >> floatVar;
    localEllipse->setY(floatVar);
    cout << "Enter radius1 (must be >= 0): ";
    cin >> floatVar;
    localEllipse->setRadius1(floatVar);
    cout << "Enter radius2 (must be >= 0): ";
    cin >> floatVar;
    localEllipse->setRadius2(floatVar);
    cout << "Enter square (must be >= 0): ";
    cin >> floatVar;
    localEllipse->setSquare(floatVar);
    cout << endl;
    return localEllipse;
}

void tableOnScreen(vector<Ellipse*> ellipses) {
    int n = ellipses.size();

    cout << setw(20) << left << "Ellipse name"
        << setw(20) << left << "Radius1"
        << setw(20) << left << "Radius2"
        << setw(20) << left << "X"
        << setw(20) << left << "Y"
        << setw(20) << left << "Square"
        << endl;

    for (int i = 0; i < n; i++) {
        ellipses[i]->printFields();
    }
}
