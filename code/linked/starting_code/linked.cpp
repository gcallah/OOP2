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


void add_at_front(Node*& head, int data) {
}


void print_list(ostream& os, Node* head, string title="") {
    /*
     * Given the head of a list, print the whole thing.
     * */
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
    return orig_head;
}


int main() {
    Node* list1 = nullptr;
//    add_at_front(list1, 2);
//    add_at_front(list1, 4);
//    add_at_front(list1, 8);
//    add_at_front(list1, 16);
//    Node* new_list = rclone(list1);
//    Node* four = rfind(list1, 4);
//    insert(four, 5);
//    cout << "Found 4? " << four << endl;
//    add_at_front(list1, 32);
//    add_at_front(new_list, 64);
    print_list(cout, list1, "List 1");
//    print_list(cout, new_list, "New list");
}
