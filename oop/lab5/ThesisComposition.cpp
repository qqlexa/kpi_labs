#include "ThesisComposition.h"

ThesisComposition::ThesisComposition() {
	countLists_ = 0;
}

ThesisComposition::ThesisComposition(vector<Thesis> composition, int year, int month, int day, int countLists): Date(year, month, day) {
	setComposition(composition);
	countLists_ = (countLists > 0) ? countLists : 0;
}

ThesisComposition::ThesisComposition(ThesisComposition& thesisComposition){
	setComposition(thesisComposition.thesisComposition_);
	countLists_ = thesisComposition.countLists_;
}

ThesisComposition::ThesisComposition(ThesisComposition* thesisComposition){
	setComposition(thesisComposition->thesisComposition_);
	countLists_ = thesisComposition->countLists_;
}

vector<Thesis> ThesisComposition::getComposition() {
	return thesisComposition_;
}

void ThesisComposition::setComposition(vector<Thesis> composition) {
	thesisComposition_.clear();
	for (Thesis thesis : composition) {
		thesisComposition_.push_back(thesis);
	}
}

void ThesisComposition::appendComposition(Thesis thesis) {
	thesisComposition_.push_back(thesis);
}

void ThesisComposition::clearComposition() {
	thesisComposition_.clear();
}


int ThesisComposition::getCountLists() {
	return countLists_;
}

void ThesisComposition::setCountLists(int countLists){
	countLists_ = countLists;
}