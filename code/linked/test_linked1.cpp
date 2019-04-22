// Creating a new type using struct:
#include <iostream>
using namespace std;

#include "linked1.h"


int main() {
    Node* head = nullptr;
    add_at_end(head, 16);
    add_at_end(head, 32);
    add_at_end(head, 64);
    add_at_end(head, 128);
    add_at_end(head, 256);
    add_at_front(head, 8);
    cout << "Last: " << last(head) << endl;
    cout << "List: \n";
    print_list(cout, head);
    Node* l2 = nullptr;
    cout << "Last l2: " << last(l2) << endl;
}

