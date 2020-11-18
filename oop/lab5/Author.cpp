#include "Author.h"
#include <iostream>

using namespace std;

Author::Author(){
	post_ = Post::STUDENT;
}

Author::Author(string name, string surname, Post post) : Person(name, surname) {
	post_ = post;
}

Author::Author(string name, string surname, Post post, int year, int month, int day) : Person(name, surname, year, month, day) {
	post_ = post;
}

Post Author::getPost() {
	return post_;
}

void Author::setPost(Post post) {
	post_ = post;
}