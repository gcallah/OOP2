// Creating a new type using struct:
#include <iostream>
#include <string>
using namespace std;

// const bool DEBUG = true;


struct Node {
    /*
     * The basic element of a linked list.
     * */
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
    int data;
    Node* next;
};


ostream& operator<<(ostream& os, Node* nd) {
    if (!nd)
        os << "NULL";
    else
        os << nd->data;
    return os;
}


Node* rfind(Node* head, int item) {
    return head;
}


bool insert(Node* prev, int new_item) {
    return true;
}


Node* rclone(Node* orig_head) {
    return orig_head;
}


Node* clone(Node* orig_head) {
    if (!orig_head) return nullptr;
    Node* new_head = new Node(orig_head->data);
    Node* curr_orig = orig_head->next;
    Node* last_copied = new_head;
    while(curr_orig) {
        last_copied->next = new Node(curr_orig->data);
        curr_orig = curr_orig->next;
        last_copied = last_copied->next;
    }
    return new_head;
}


Node* last(Node* head) {
    if (!head) return nullptr;
    else {
        Node* np = head;
        while (np->next) np = np->next;
        return np;
    }
}


void add_at_front(Node*& head, int data) {
    head = new Node(data, head);
}


void add_at_end(Node* head, int data) {
    Node* end = last(head);
    if (!end)
        add_at_front(head, data);
    else
        end->next = new Node(data);
}


void print_list(ostream& os, Node* head, string title="") {
    /*
     * Given the head of a list, print the whole thing.
     * */
    if (title.size()) os << title << ": ";
    if (head) {
        os << head << " --> ";
        print_list(os, head->next);
    }
    else os << "NULL" << endl;
}


int main() {
    Node* list1 = nullptr;
    add_at_front(list1, 2);
    add_at_front(list1, 4);
    add_at_front(list1, 8);
    add_at_front(list1, 16);
    Node* last_node = last(list1);
    cout << "last node of list1 = " << last_node << endl;
    add_at_end(list1, 1);
    last_node = last(list1);
    cout << "last node of list1 = " << last_node << endl;
    Node* new_list = clone(list1);
    print_list(cout, list1, "List 1");
//    Node* four = rfind(list1, 4);
//    insert(four, 5);
//    cout << "Found 4? " << four << endl;
//    add_at_front(list1, 32);
//    add_at_front(new_list, 64);
    print_list(cout, list1, "List 1");
//    print_list(cout, new_list, "New list");
}
