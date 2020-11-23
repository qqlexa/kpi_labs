#include "Author.h"
#include <iostream>

using namespace std;

Author::Author(){
	post_ = Post::STUDENT;
}

Author::Author(string name, string surname, Post post) : Person(name, surname) {
	post_ = post;
}

Author::Author(string name, string surname, int year, int month, int day, Post post) : Person(name, surname, year, month, day) {
	post_ = post;
}

Author::Author(string name, string surname, Date date, Post post) : Person(name, surname, date) {
	post_ = post;
}

Author::Author(Author& author) : Person(author.getPerson()) {
	post_ = author.post_;
}

Author::Author(Author* author) : Person(author->getPerson()) {
	post_ = author->post_;
}

Author::Author(Person person, Post post) : Person(person) {
	post_ = post;
}

Post Author::getPost() {
	return post_;
}

void Author::setPost(Post post) {
	post_ = post;
}

Author& Author::getAuthor() {
	return *this;
}
