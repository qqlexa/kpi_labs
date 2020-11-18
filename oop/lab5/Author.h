#pragma once
#include "Person.h"
#include <iostream>

enum class Post {
    STUDENT,       // 0
    SPECIALIST,    // 1
    MASTER,        // 2
    POSTGRADUATE,  // 3
    ASSISTANT,     // 4
    TEACHER,       // 5
    DOCENT,        // 6
    PROFESSOR,     // 7
};

class Author :
    public Person
{
private:
    Post post_;
public:
    Author();
    Author(string, string, Post);
    Author(string, string, Post, int, int, int);

    Post getPost();
    void setPost(Post);
};

