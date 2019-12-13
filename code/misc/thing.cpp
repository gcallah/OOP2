
/*
 * `thing.cpp` is designed to illustrate basic memory management.
 * */
#include <iostream>
#include <vector>
using namespace std;

/*
 * We define a simple structure with a constructor and a single field.
 * */
struct Thing {
    int val;
//    Thing(int i) : val(i) {}
};

/*
 * In `main()` we are going to
 * allocate an array of 100 `Thing` pointers,
 * fill it with `Thing`s, change their values,
 * and then delete them:
 * */
int main() {
    // allocate array:
    Thing** data = new Thing*[100];
    const int x = 7;
    int* iptr = &x;
    x = 17;

    // Fill array with Things:
    for (int i = 0; i < 100; i++) {
        data[i] = new Thing{i + 1};
    }

    // Change their values:
    for (int i = 0; i < 100; i++) {
        data[i]->val += i;
        cout << "data[" << i << "] == " << data[i]->val << endl;
    }
}
