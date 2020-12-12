#include <iostream>

#include "Author.h"

using namespace std;

Author::Author(){
	post_ = Post::STUDENT;
}

Author::Author(string name, string surname, int year, int month, int day, Post post) : Person(name, surname, year, month, day) {
	post_ = post;
}

Author::Author(Author& author){
	post_ = author.post_;
}

Post Author::getPost() {
	return post_;
}

void Author::setPost(Post post) {
	post_ = post;
}

void Author::show() {
	switch (post_) {
	case Post::STUDENT: {
		cout << "Student" << endl;
	} break;
	case Post::SPECIALIST: {
		cout << "SPECIALIST" << endl;
	} break;
	case Post::MASTER: {
		cout << "MASTER" << endl;
	} break;
	case Post::POSTGRADUATE: {
		cout << "POSTGRADUATE" << endl;
	} break;
	case Post::ASSISTANT: {
		cout << "ASSISTANT" << endl;
	} break;
	case Post::TEACHER: {
		cout << "TEACHER" << endl;
	} break;
	case Post::DOCENT: {
		cout << "DOCENT" << endl;
	} break;
	case Post::PROFESSOR: {
		cout << "PROFESSOR" << endl;
	} break;
	default:
		break;
	}
	Person::show();
}
