#pragma once
#include "Author.h"
class AuthorBoss :
    public Author
{
public:
    AuthorBoss();
    AuthorBoss(Author&);
    AuthorBoss(Author*);
};

