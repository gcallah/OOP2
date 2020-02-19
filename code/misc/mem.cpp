
/*
 * Experiments with memory, illustrating the use of
 * memory operators and `sizeof()`.
 * */

#include <iostream>

using namespace std;


int main() {
    /*
     * Let's look at the size of some data types:
     * */
    bool b = true;
    cout << "Size of a bool = " << sizeof(b) << endl;
    char c = 'a';
    cout << "Size of a char = " << sizeof(c) << endl;
    int i = 28;
    cout << "Size of an integer = " << sizeof(i) << endl;
    double d = 2.71828;
    cout << "Size of a double = " << sizeof(d) << endl;

    /*
     * Now let's deal with addresses and pointers:
     * */
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

    /*
     * Hmm, what is the size of a pointer?
     * Is it different for different pointers?
     * */
    cout << "Size of a bool ptr = " << sizeof(bptr) << endl;
    cout << "Size of an integer ptr = " << sizeof(iptr) << endl;
    cout << "Size of a double ptr = " << sizeof(dptr) << endl;

    /*
     * Seems like all pointers are the same size! Since C++
     * references are "really" a sort of pointer, this explains
     * why, for large objects, it is much more efficient, for 
     * objects we don't want changed in a function,
     * (if we want to change the object in a function 
     * it's clear we *can't* pass a copy!) to pass a
     * constant reference than to pass a copy: the reference
     * will be essentially an 8-byte address, while the copy 
     * might be a multi-gigabyte video segment.
     *
     * So, if we have pointer to some value, how do we get
     * the value? We *dereference* the pointer.
     * */
    cout << "Value pointed to by bptr = " << *bptr << endl;
    cout << "Value pointed to by iptr = " << *iptr << endl;
    cout << "Value pointed to by dptr = " << *dptr << endl;

}

