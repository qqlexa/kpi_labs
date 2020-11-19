#include "Author2.h"
#include <iostream>

using namespace std;

Author2::Author2() {
	post_ = Post::STUDENT;
}

Author2::Author2(string name, string surname, Post post) : Person(name, surname) {
	post_ = post;
}

Author2::Author2(string name, string surname, Post post, int year, int month, int day) : Person(name, surname, year, month, day) {
	post_ = post;
}

Post Author2::getPost() {
	return post_;
}

void Author2::setPost(Post post) {
	post_ = post;
}