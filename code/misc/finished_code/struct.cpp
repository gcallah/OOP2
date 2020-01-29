
/*
 * `struct.cpp` is designed to demonstrate a simple structure.
 * */
#include <iostream>
#include <vector>
using namespace std;

/*
 * We define a simple structure with a constructor and a single field.
 * */
struct Thing {
    int val;
};

/*
 * Fill a `vector` of `Things`. Loop over them and change their values.
 * */
int main() {
    Thing t1, t2;
    t1.val = 7;
    t2.val = 8;

    // if (t1 == t2) cout << "t1 and t2 are the same.\n";
    // else cout << "t1 and t2 are not the same.\n";

    cout << "t1: " << t1.val << "; t2: " << t2.val << endl;
}
