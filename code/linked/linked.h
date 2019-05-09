#ifndef LINKED_H
#define LINKED_H

#include <iostream>

const bool DEBUG = true;


/*
 * The struct `Node`, which is the building block of our linked list code.
 * */
struct Node {
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
    int data;
    Node* next;
};


/*
 * Linked list iterator:
 * This class supports ranged for loops on linked lists.
 * It includes:
 * Iterator(Node*)
 * operator++
 * operator*
 * operator!=
 * */
class LLIterator {
        friend bool operator!=(const LLIterator& rhs, const LLIterator& lhs) {
            return rhs.nptr != lhs.nptr;
        }

    public:
        /*
         * We create the iterator by initing it with the head pointer of
         * the list.
         * */
        LLIterator(Node* head) : nptr(head) {}

        /*
         * The ++ operator advances the iterator to the next element.
         * */
        LLIterator operator++() {
            nptr = nptr->next;
            return *this;
        }

        /*
         * The * operator gets us back the underlying value we 
         * have reached in ou iteration.
         * */
        int operator*() { return nptr->data; }

    private:
        Node* nptr;
};

/*
 * Our linked list class.
 * */
class LinkedList {
    LinkedList() : head(nullptr) {}

    const LLIterator begin() const { return LLIterator(head); }
    const LLIterator end() const { return LLIterator(nullptr); }

    private:
        Node* head;
};


/*
 * The various functions that can operate on our linked lists:
 * */
ostream& operator<<(ostream& os, Node* nd);
Node* last(Node* head);
void add_at_front(Node*& head, int d);
void add_at_end(Node*& head, int d);
void print_list(ostream& os, Node* curr);
bool del_head(Node*& head);
bool del_tail(Node** prev_next);
Node* duplicate(Node* head);
Node* reverse(Node* curr, Node* prev=nullptr);

#endif
