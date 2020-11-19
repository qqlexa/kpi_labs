#include "Thesis.h"

Thesis::Thesis() {
    name_ = "Thesis";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(Date, AuthorStudent, AuthorBoss) {
    name_ = "Thesis";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(Date, AuthorStudent, AuthorBoss, string, int, int, float) {
    name_ = "Thesis";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

string Thesis::getName() {
    return name_;
}

void Thesis::setName(string name) {
    name_ = name;
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

Thesis& Thesis::getThesis() {
    return *this;
}