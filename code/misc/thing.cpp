
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
    const Thing zero = Thing(0);
    vector<Thing*> things;

    // Fill array with Things:
    for (int i = 0; i < 100; i++) {
        things.push_back(new Thing(zero));
        cout << "things " << i << " = " << things[i]->val << " ";
        if ((i % 5) == 4) cout << endl;
    }

    // Change their values:
    for (int i = 0; i < 100; i++) {
        things[i]->val += i;
        cout << "things " << i << " = " << things[i]->val << " ";
        if ((i % 5) == 4) cout << endl;
    }
    cout << endl;

    // delete them:
    for (int i = 0; i < 100; i++) {
        delete things[i];
    }

}
