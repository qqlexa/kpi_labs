#include "ThesisComposition.h"

ThesisComposition::ThesisComposition() {
	countLists_ = 0;
}

ThesisComposition::ThesisComposition(vector<Thesis> composition, Date date, int countLists): Date(date) {
	setComposition(composition);
	countLists_ = (countLists > 0) ? countLists : 0;
}

ThesisComposition::ThesisComposition(ThesisComposition& thesisComposition): Date(thesisComposition.getDate()) {

}

ThesisComposition::ThesisComposition(ThesisComposition* thesisComposition) : Date(thesisComposition->getDate()) {

}

vector<Thesis> ThesisComposition::getComposition() {
	return composition_;
}

void ThesisComposition::setComposition(vector<Thesis> composition) {
	composition_.clear();
	for (Thesis thesis : composition) {
		composition_.push_back(thesis);
	}
}

void ThesisComposition::appendComposition(Thesis thesis) {
	composition_.push_back(thesis);
}

void ThesisComposition::clearComposition() {
	composition_.clear();
}


int ThesisComposition::getCountLists() {
	return countLists_;
}

void ThesisComposition::setCountLists(int countLists){
	countLists_ = countLists;
}