#include "Thesis.h"

Thesis::Thesis() {
    authorStudent_ = Author();
    authorBoss_ = Author();

    drawName_ = "drawName";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(int year, int month, int day,
    string firstName1, string secondName1, int year1, int month1, int day1, Post post1,
    string firstName2, string secondName2, int year2, int month2, int day2, Post post2,
    string drawName, int countDraws, int countLinks, float amountLists): Date(year, month, day){

    authorStudent_ = Author(firstName1, secondName1, year1, month1, day1, post1);
    authorBoss_ = Author(firstName2, secondName2, year2, month2, day2, post2);

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

Thesis::Thesis(Thesis* thesis) {
    authorStudent_ = thesis->authorStudent_;
    authorBoss_ = thesis->authorBoss_;
    drawName_ = thesis->drawName_;
    countDraws_ = thesis->countDraws_;
    countLinks_ = thesis->countLinks_;
    amountLists_ = thesis->amountLists_;
}

Author Thesis::getAuthorStudent() {
    return authorStudent_;
}

void Thesis::setAuthorStudent(Author authorStudent) {
    authorStudent_ = authorStudent;
}

Author Thesis::getAuthorBoss() {
    return authorBoss_;
}

void Thesis::setAuthorBoss(Author authorBoss) {
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
