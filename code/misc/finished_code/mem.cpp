
/*
 * Experiments with memory, illustrating the use of
 * memory operators and `sizeof()`.
 * */

#include <iostream>

using namespace std;


int main() {
    // let's look at the size of some data types:
    bool b = true;
    cout << "Size of a bool = " << sizeof(b) << endl;
    char c = 'a';
    cout << "Size of a char = " << sizeof(c) << endl;
    int i = 0;
    cout << "Size of an integer = " << sizeof(i) << endl;
    double d = 0.0;
    cout << "Size of a double = " << sizeof(d) << endl;

    // now let's deal with addresses and pointers:
    cout << "Address of b = " << &b << endl;
    bool* bptr = &b;
    cout << "Value of bptr = " << bptr << endl;
    // funkiness coming: `char *`s are C-style strings!
    cout << "Address of c = " << &c << endl;
    // actually get the address:
    cout << "Address of c as void ptr = " << (void *) &c << endl;
    // better C++ way to do this:
    cout << "Address of c as static cast void ptr = "
        << static_cast<const void *> (&c) << endl;
    cout << "Address of i = " << &i << endl;
    int* iptr = &i;
    cout << "Value of iptr = " << iptr << endl;
    cout << "Address of d= " << &d << endl;
    double* dptr = &d;
    cout << "Value of dptr = " << dptr << endl;
}

