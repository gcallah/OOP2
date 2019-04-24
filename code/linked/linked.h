// Creating a new type using struct:
#include <iostream>

const bool DEBUG = true;

struct Node {
    /*
     * The basic element of a linked list.
     * */
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
    int data;
    Node* next;
};

ostream& operator<<(ostream& os, Node* nd);
Node* last(Node* head);
void add_at_front(Node*& head, int d);
void add_at_end(Node*& head, int d);
void print_list(ostream& os, Node* head);
bool del_head(Node*& head);
bool del_tail(Node** prev_next);
Node* duplicate(Node* head);
