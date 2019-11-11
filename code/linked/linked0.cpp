// Creating a new type using struct:
#include <iostream>
using namespace std;

const bool DEBUG = true;


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


int main() {
    Node* new_list = nullptr;
    print_list(cout, new_list);
}
