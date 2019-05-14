
/*
 * A linked list class, demonstrating the use of pointers,
 * and several recursive methods.
 * */
#include <iostream>
using namespace std;

#include "linked.h"


/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, Node* nd) {
    if (!nd) os << "NULL";
    else os << nd->data;
    return os;
}


/*
 * Reverse a linked list.
 * This code creates a *copy* of the original list.
 * */
Node* reverse(Node* curr, Node* new_next) {
    if (curr == nullptr) return new_next;
    else {
        new_next = new Node(curr->data, new_next);
        return reverse(curr->next, new_next);
    }
}


/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * Let's define this recursively!
 * */
Node* last(Node* head) {
    if (!head) return nullptr;
    Node* np = head;
    while(np->next) np = np->next;
    return np;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    Node* end = last(head);
    if (!end)
        add_at_front(head, d);
    else
        end->next = new Node(d);
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, Node* curr) {
    if (curr) {
        os << curr << " ";
        print_list(os, curr->next);
    }
    else os << endl;
}


/*
 * Delete the front of a list.
 * */
bool del_head(Node*& head) {
    if (!head) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}


bool del_tail(Node** prev_next) {
    if ((*prev_next) == nullptr) return false;
    Node* curr = *prev_next;
    while (curr->next) {
        prev_next = &(curr->next);
        curr = curr->next;
    }
    delete curr;
    (*prev_next) = nullptr;
    return true;
}


Node* duplicate1(Node* head) {
    Node* new_head = nullptr;
    Node* curr = head;
    while(curr) {
        add_at_end(new_head, curr->data);
        curr = curr->next;
    }
    return new_head;
}

Node* duplicate(Node* head) {
    if (!head) return nullptr;
    else return new Node(head->data, duplicate(head->next));
}
