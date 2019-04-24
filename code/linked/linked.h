// Creating a new type using struct:
#include <iostream>

const bool DEBUG = true;

class LLIterator {
    /*
     * This class supports ranged for loops on linked lists.
     * It includes:
     * Iterator(Node*)
     * operator++
     * operator*
     * operator!=
     * */
        friend bool operator!=(const LLIterator& rhs, const LLIterator& lhs) {
            return rhs.nptr != lhs.nptr;
        }

    public:
        LLIterator(Node* head) : nptr(head) {}

        LLIterator operator++() {
            nptr = nptr->next;
            return *this;
        }

        int operator*() { return nptr->data; }

    private:
        Node* nptr;
};

struct Node {
    /*
     * The basic element of a linked list.
     * */
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
    int data;
    Node* next;
};

class LinkedList {
    LinkedList() : head(nullptr) {}

    Iterator& begin() { return Iterator(head);
    Iterator& end() { return Iterator(nullptr);

    private:
        Node* head;
};


ostream& operator<<(ostream& os, Node* nd);
Node* last(Node* head);
void add_at_front(Node*& head, int d);
void add_at_end(Node*& head, int d);
void print_list(ostream& os, Node* head);
bool del_head(Node*& head);
bool del_tail(Node** prev_next);
Node* duplicate(Node* head);
