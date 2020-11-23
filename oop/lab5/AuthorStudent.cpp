#include "AuthorStudent.h"

AuthorStudent::AuthorStudent() {
}
AuthorStudent::AuthorStudent(Author& author) : Author(author) {
}
AuthorStudent::AuthorStudent(Author* author) : Author(author) {
}
