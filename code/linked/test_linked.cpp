// Creating a new type using struct:
#include <iostream>
using namespace std;

#include "linked.h"


int main() {
    Node* head = nullptr;
    add_at_end(head, 16);
    add_at_end(head, 32);
    add_at_end(head, 64);
    add_at_end(head, 128);
    add_at_end(head, 256);
    add_at_front(head, 8);
    Node* lastp = last(head);
    cout << "Last: " << lastp << endl;
    cout << "List: \n";
    print_list(cout, head);
    Node* l2 = nullptr;
    cout << "Last l2: " << last(l2) << endl;
    Node* head2 = duplicate(head);
    del_head(head);
    del_tail(&head);
    del_tail(&head);
    cout << "List after deletes: \n";
    print_list(cout, head);
    bool worked = del_head(l2);
    cout << "Did it work? " << worked << endl;
    print_list(cout, head2);
}

