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


Node* clone(Node* head) {
    if (!head) return nullptr;
    else {
        return new Node(head->data, clone(head->next));
    }
}


Node* duplicate(Node* head) {
    if (!head) return nullptr;

    Node* new_head = nullptr;
    Node* curr = head;
    while (curr) {
        // using add_at_end() makes this expensive!
        add_at_end(new_head, curr->data);
        curr = curr->next;
    }
    return new_head;
}


void del_node(Node*& prev_next) {
    if (prev_next != nullptr) {
        Node* temp = prev_next->next;
        delete (*prev_next);
        *prev_next = temp;
    }
}


bool del_head(Node*& head) {
    if (head == nullptr) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

