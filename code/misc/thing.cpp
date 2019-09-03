
/*
 * `thing.cpp` is designed to illustrate basic memory management.
 * */
#include <iostream>
using namespace std;

/*
 * We define a simple structure with a constructor and a single field.
 * */
struct Thing {
    int val;
    Thing(int i) : val(i) {}
};

/*
 * In `main()` we are going to
 * allocate an array of 100 `Thing` pointers,
 * fill it with `Thing`s, change their values,
 * and then delete them:
 * */
int main() {
    // allocate array:
    Thing** datap = new Thing*[100];

    // Fill array with Things:
    for (int i = 0; i < 100; i++)
        datap[i] = new Thing(i);

    // Change their values:
    for (int i = 0; i < 100; i++) {
        datap[i]->val += i;
        cout << "datap " << i << " = " << datap[i]->val << " ";
        if ((i % 5) == 4) cout << endl;
    }
    cout << endl;

    // delete them:
    for (int i = 0; i < 100; i++) {
        delete datap[i];
    }

    // and delete the array itself:
    delete[] datap;
}
