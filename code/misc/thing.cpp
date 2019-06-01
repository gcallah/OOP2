#include <iostream>
using namespace std;

/*
 * A simple structure with a constructor.
 * */
struct Thing {
    int val;
    Thing(int i) : val(i) {}
};

/*
 * Allocate an array of 100 Thing pointers,
 * fill it with Things, change their values,
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
    }
    cout << endl;

    // delete them:
    for (int i = 0; i < 100; i++) {
        delete datap[i];
    }
}
