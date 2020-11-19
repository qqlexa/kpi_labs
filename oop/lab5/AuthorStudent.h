#pragma once
#include "Author.h"
class AuthorStudent :
    public Author
{
public:
    AuthorStudent();
    AuthorStudent(Author&);
    AuthorStudent(Author*);
};

