#include "AuthorBoss.h"

AuthorBoss::AuthorBoss() {
}
AuthorBoss::AuthorBoss(Author& author) : Author(author) {
}
AuthorBoss::AuthorBoss(Author* author) : Author(author) {
}