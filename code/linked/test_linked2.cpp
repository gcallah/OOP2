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
    cout << "Last: " << last(head) << endl;
    cout << "List: \n";
    print_list(cout, head);
    Node* head2 = duplicate(head);
    Node* lempty = nullptr;
    cout << "Last lempty: " << last(lempty) << endl;
    del_head(lempty);
    cout << "List: \n";
    print_list(cout, head);
    cout << "List 2: \n";
    print_list(cout, head2);
}

