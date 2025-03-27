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
    u->name = (char*)malloc(strlen(name) + 1);  // Allocate memory for the name
    strcpy_s(u->name, strlen(name) + 1, name);  // Use strcpy_s instead of strcpy
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
    if (!root) return;
    freeTree(root->leftFriend);
    freeTree(root->rightFriend);
    free(root->name);
    free(root);
}

int main5() {
    User* root = createUser("Alice");

    User* bob = createUser("Bob");
    User* carol = createUser("Carol");

    connectFriends(root, bob, carol);

    User* eve = createUser("Eve");
    connectFriends(bob, eve, NULL);
    eve = createUser("EveShadow");

    printTree(root);
    freeTree(root);
    return 0;
}