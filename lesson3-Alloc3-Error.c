#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    char* name;
    struct User* leftFriend;
    struct User* rightFriend;
} User;

User* createUser(const char* name) {
    User* u = (User*)malloc(sizeof(User));
    u->name = (char*)malloc(strlen(name) + 1);
    strcpy(u->name, name);
    u->leftFriend = NULL;
    u->rightFriend = NULL;
    return u;
}

void connectFriends(User* root, User* left, User* right) {
    root->leftFriend = left;
    root->rightFriend = right;
}

void printTree(User* root) {
    if (!root) return;
    printf("User: %s\n", root->name);
    printTree(root->leftFriend);
    printTree(root->rightFriend);
}

void freeTree(User* root) {
    if (!root)