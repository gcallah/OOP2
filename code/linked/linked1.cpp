// Creating a new type using struct:
#include <iostream>
using namespace std;

#include "linked1.h"


ostream& operator<<(ostream& os, Node* nd) {
    os << nd->data;
    return os;
}
