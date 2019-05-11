
/*
 * A test "suite" for our linked list code.
 * */
#include <iostream>
#include <cassert>
using namespace std;

#include "linked.h"


/*
 * Our `main()` will exercise the various linked list 
 * capabilities that we have built.
 * */
int main() {
    Node* head = nullptr;
    add_at_end(head, 16);
    add_at_end(head, 32);
    add_at_end(head, 64);
    add_at_end(head, 128);
    add_at_end(head, 256);
    add_at_front(head, 8);
    assert(head->data == 8);

    // let's see if our last() function works:
    Node* lastp = last(head);
    assert(lastp->data == 256);
    cout << "Last: " << lastp << endl;

    cout << "List: \n";
    print_list(cout, head);
    Node* rev = reverse(head);
    assert(rev->data == 256);
    cout << "reverse: \n";
    print_list(cout, rev);

    Node* head2 = duplicate(head);
    del_head(head);
    // &head gives us a pointer to a pointer
    del_tail(&head);
    del_tail(&head);
    assert(head->data == 16);
    cout << "List after deletes: \n";
    print_list(cout, head);

    Node* l2 = nullptr;
    cout << "Last l2: " << last(l2) << endl;
    bool worked = del_head(l2);
    assert(!worked);
    cout << "Did del_head() work? " << worked << endl;
    print_list(cout, head2);
}
