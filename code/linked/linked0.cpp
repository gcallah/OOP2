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
    head = new Node(data, head);
}


void print_list(ostream& os, Node* head, string title="") {
    /*
     * Given the head of a list, print the whole thing.
     * */
    os << title << endl;

    Node* np = head;
    while (np) {
        os << np << " ";
        np = np->next;
    }
    os << endl;
}


Node* rfind(Node* head, int item) {
    if (!head) return nullptr;
    else if (head->data == item) return head;
    else return rfind(head->next, item);
}


bool insert(Node* prev, int new_item) {
    if (!prev) return false;
    else {
        prev->next = new Node(new_item, prev->next);
        return true;
    }
}


Node* rclone(Node* orig_head) {
    if (!orig_head) return nullptr;
    else return new Node(orig_head->data, rclone(orig_head->next));
}


Node* clone(Node* orig_head) {
    if (!orig_head) return nullptr;

    Node* new_head = new Node(orig_head->data);
    Node* new_last = new_head;
    Node* orig_next = orig_head->next;
    while (orig_next) {
        new_last->next = new Node(orig_next->data);
        orig_next = orig_next->next;
        new_last = new_last->next;
    }
    return new_head;
}


int main() {
    Node* list1 = nullptr;
    add_at_front(list1, 2);
    add_at_front(list1, 4);
    add_at_front(list1, 8);
    add_at_front(list1, 16);
    Node* new_list = rclone(list1);
    Node* four = rfind(list1, 4);
    insert(four, 5);
    cout << "Found 4? " << four << endl;
    add_at_front(list1, 32);
    add_at_front(new_list, 64);
    print_list(cout, list1, "List 1");
    print_list(cout, new_list, "New list");
}
