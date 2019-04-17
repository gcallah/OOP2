// Creating a new type using struct:
#include <iostream>

const bool DEBUG = true;

struct Node {
    /*
     * The basic element of a linked list.
     * */
    Node(int d, Node* n) : data(d), next(n) {}
    int data;
    Node* next;
};

ostream& operator<<(ostream& os, Node* nd);

