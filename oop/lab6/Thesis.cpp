#include "Thesis.h"

Thesis::Thesis() {
    // authorStudent_ = Author(); // automatic call
    // authorBoss_ = Author();    // automatic call

    drawName_ = "drawName";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(int year, int month, int day,
    string firstName1, string secondName1, int year1, int month1, int day1, Post post1,
    string firstName2, string secondName2, int year2, int month2, int day2, Post post2,
    string drawName, int countDraws, int countLinks, float amountLists): Date(year, month, day){

    authorStudent_.setFirstName(firstName1);
    authorStudent_.setSecondName(secondName1);
    authorStudent_.setYear(year1);
    authorStudent_.setMonth(month1);
    authorStudent_.setDay(day1);
    authorStudent_.setPost(post1);

    authorBoss_.setFirstName(firstName2);
    authorBoss_.setSecondName(secondName2);
    authorBoss_.setYear(year2);
    authorBoss_.setMonth(month2);
    authorBoss_.setDay(day2);
    authorBoss_.setPost(post2);

    drawName_ = drawName;
    countDraws_ = countDraws;
    countLinks_ = countLinks;
    amountLists_ = amountLists;
}

Thesis::Thesis(Thesis& thesis) {
    authorStudent_ = thesis.authorStudent_;
    authorBoss_ = thesis.authorBoss_;
    drawName_ = thesis.drawName_;
    countDraws_ = thesis.countDraws_;
    countLinks_ = thesis.countLinks_;
    amountLists_ = thesis.amountLists_;
}

Thesis::Thesis(const Thesis& thesis) {
    authorStudent_ = thesis.authorStudent_;
    authorBoss_ = thesis.authorBoss_;
    drawName_ = thesis.drawName_;
    countDraws_ = thesis.countDraws_;
    countLinks_ = thesis.countLinks_;
    amountLists_ = thesis.amountLists_;
}

Author& Thesis::getAuthorStudent() {
    return authorStudent_;
}

void Thesis::setAuthorStudent(Author& authorStudent) {
    authorStudent_ = authorStudent;
}

Author& Thesis::getAuthorBoss() {
    return authorBoss_;
}

void Thesis::setAuthorBoss(Author& authorBoss) {
    authorBoss_ = authorBoss;
}

string Thesis::getDrawName() {
    return drawName_;
}

void Thesis::setDrawName(string drawName) {
    drawName_ = drawName;
}


int Thesis::getCountDraws() {
    return countDraws_;
}

void Thesis::setCountDraws(int countDraws) {
    countDraws_ = (countDraws > 0) ? countDraws : 0;
}

int Thesis::getCountLinks() {
    return countLinks_;
}

void Thesis::setCountLinks(int countLinks) {
    countLinks_ = (countLinks > 0) ? countLinks : 0;
}

float Thesis::getAmountLists() {
    return amountLists_;
}

void Thesis::setAmountLists(float amountLists) {
    amountLists_ = (amountLists > 0) ? amountLists : 0;
}

void Thesis::show() {
    authorStudent_.show();
    authorBoss_.show();

    cout << "drawName_: " << drawName_ << endl;
    cout << "countDraws_ = " << countDraws_ << endl;
    cout << "countLinks_ = " << countLinks_ << endl;
    cout << "amountLists_ = " << amountLists_ << endl;
    Date::show();
}
