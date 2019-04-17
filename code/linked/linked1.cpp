// Creating a new type using struct:
#include <iostream>
using namespace std;

#include "linked1.h"


ostream& operator<<(ostream& os, Node* nd) {
    if (!nd)
        os << "NULL";
    else
        os << nd->data;
    return os;
}


void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


Node* last(Node* head) {
    if (!head) return nullptr;
    Node* np = head;
    while(np->next) np = np->next;
    return np;
}


void add_at_end(Node*& head, int d) {
    Node* end = last(head);
    if (!end)
        add_at_front(head, d);
    else
        end->next = new Node(d);
}


void print_list(ostream& os, Node* head) {
    /*
     * Given the head of a list, print the whole thing.
     * */
    Node* np = head;
    while (np) {
        os << np << " ";
        np = np->next;
    }
    os << endl;
}
