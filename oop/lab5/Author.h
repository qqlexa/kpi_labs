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
    virtual public Person
{
private:
    Post post_;
public:
    Author();
    Author(string, string, Post);
    Author(string, string, int, int, int, Post);
    Author(string, string, Date, Post);
    Author(Person, Post);

    Author(Author&);
    Author(Author*);

    Post getPost();
    void setPost(Post);

    Author& getAuthor();
};

