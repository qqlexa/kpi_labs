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

Author::Author(Author* author){
	post_ = author->post_;
}

Post Author::getPost() {
	return post_;
}

void Author::setPost(Post post) {
	post_ = post;
}
