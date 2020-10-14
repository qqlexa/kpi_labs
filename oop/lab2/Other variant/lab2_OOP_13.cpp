#include <iostream>
#include <iomanip>
#include <string>
#include "Ellipse.h"
#include <vector>

using namespace std;

Ellipse* createEllipseByInput();
void tablePartOnScreen(std::string, std::string*, int);
void tableOnScreen(vector<Ellipse*>);

int main(){
    vector<Ellipse*> ellipses;
    string userInput = "";
    ellipses.push_back(new Ellipse("First"));
    ellipses.push_back(new Ellipse("Second"));
    tableOnScreen(ellipses);
    while (true) {
        cout <<
            "0) exit" << endl <<
            "1) add ellipse" << endl <<
            "2) print table" << endl <<
            "$ ";
        getline(cin, userInput);
        if (userInput == "0") {
            exit(1);
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
  

    return 1;
}

Ellipse* createEllipseByInput() {
    Ellipse* localEllipse = new Ellipse();
    string userInput = "";
    float floatVar = 0;
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

    cout << endl << setw(20) << left << "Field/Ellipse";
    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << ellipses[i]->getName();
    }
    cout << endl;
    string* strings = new string[n];
    for (int i = 0; i < n; i++) {
        strings[i] = to_string(ellipses[i]->getX());
    }
    tablePartOnScreen("X", strings, n);
    for (int i = 0; i < n; i++) {
        strings[i] = to_string(ellipses[i]->getY());
    }
    tablePartOnScreen("Y", strings, n);
    for (int i = 0; i < n; i++) {
        strings[i] = to_string(ellipses[i]->getRadius1());
    }
    tablePartOnScreen("Radius1", strings, n);
    for (int i = 0; i < n; i++) {
        strings[i] = to_string(ellipses[i]->getRadius2());
    }
    tablePartOnScreen("Radius2", strings, n);
    for (int i = 0; i < n; i++) {
        strings[i] = to_string(ellipses[i]->getSquare());
    }
    tablePartOnScreen("Square", strings, n);
    cout << endl;
    delete[]strings;
}

void tablePartOnScreen(std::string field, std::string* strings, int n) {
    using namespace std;
    cout << setw(20) << left << field;
    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << strings[i];
    }
    cout << endl;
}