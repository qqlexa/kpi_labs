#include "Thesis.h"

Thesis::Thesis() {
    name_ = "Thesis";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(Date* date, AuthorStudent* authorStudent, AuthorBoss* authorBoss) :
    Date(date),
    AuthorStudent(authorStudent),
    AuthorBoss(authorBoss) {
    name_ = "Thesis";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(Date* date, AuthorStudent* authorStudent, AuthorBoss* authorBoss, string name, int countDraws, int countLinks, float amountLists) :
    Date(date),
    AuthorStudent(authorStudent),
    AuthorBoss(authorBoss) {
    name_ = name;
    countDraws_ = countDraws;
    countLinks_ = countLinks;
    amountLists_ = amountLists;
}

Thesis::Thesis(Date date, AuthorStudent authorStudent, AuthorBoss authorBoss): 
    Date(date),
    AuthorStudent(authorStudent),
    AuthorBoss(authorBoss) {
    name_ = "Thesis";
    countDraws_ = 0;
    countLinks_ = 0;
    amountLists_ = 0;
}

Thesis::Thesis(Date date, AuthorStudent authorStudent, AuthorBoss authorBoss, string name, int countDraws, int countLinks, float amountLists) :
    Date(date),
    AuthorStudent(authorStudent),
    AuthorBoss(authorBoss) {
    name_ = name;
    countDraws_ = countDraws;
    countLinks_ = countLinks;
    amountLists_ = amountLists;
}

Thesis::Thesis(const Thesis& thesis) {
    createdThesis_ = thesis.createdThesis_;
    name_ = thesis.name_;
    countDraws_ = thesis.countDraws_;
    countLinks_ = thesis.countLinks_;
    amountLists_ = thesis.amountLists_;
}

Thesis::Thesis(const Thesis* thesis) {
    createdThesis_ = thesis->createdThesis_;
    name_ = thesis->name_;
    countDraws_ = thesis->countDraws_;
    countLinks_ = thesis->countLinks_;
    amountLists_ = thesis->amountLists_;
}

Thesis::Thesis(Thesis& thesis) : AuthorStudent(thesis.AuthorStudent::getAuthor()), AuthorBoss(thesis.AuthorBoss::getAuthor()) {
    createdThesis_ = thesis.createdThesis_;
    name_ = thesis.name_;
    countDraws_ = thesis.countDraws_;
    countLinks_ = thesis.countLinks_;
    amountLists_ = thesis.amountLists_;
}

Thesis::Thesis(Thesis* thesis) : AuthorStudent(thesis->AuthorStudent::getAuthor()), AuthorBoss(thesis->AuthorBoss::getAuthor()) {
    createdThesis_ = thesis->createdThesis_;
    name_ = thesis->name_;
    countDraws_ = thesis->countDraws_;
    countLinks_ = thesis->countLinks_;
    amountLists_ = thesis->amountLists_;
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