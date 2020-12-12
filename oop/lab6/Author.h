#pragma once
#include <iostream>

#include "Person.h"
#include "Post.h"


class Author :
    public Person
{
protected:
    Post post_;
public:
    Author();
    Author(string, string, int, int, int, Post);

    Author(Author&);

    Post getPost();
    void setPost(Post);

    virtual void show();
};

