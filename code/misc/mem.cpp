
/*
 * Experiments with memory, illustrating the use of
 * memory operators and `sizeof()`.
 * */

#include <cstddef>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * f() exists to help us further explore the stack!
 * */
int f(int n, byte* end) {
    int j = n;
    int k = n % 23;
    cout << "Address of j = " << &j << endl;
    cout << "Address of k = " << &k << endl;
    // do a hex dump of the stack between f() and main()
    int i = 0;
    for (byte* bptr = (byte *) &j;
         bptr < end;
         bptr++, i++) {
        cout << hex << setfill('0') << setw(2)
            << (int)*bptr << " ";
        if (i % 8 == 7) cout << endl;
    }
    return j - k * 7;
}


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

    /*
     * All of what we have done so far has happened on
     * the *stack*: all the memory allocation has happened automatically
     * for us, performed by the compiler and C++ run-time system.
     * But C++ allows as to also allocate memory ourselves, 
     * on the *heap*.
     * */
    int* iptr2 = new int(7);
    cout << "Value pointed to by iptr2 = " << *iptr2 << endl;
    /*
     * But note the address of this value, compared to the
     * pointers set above:
     * */
    cout << "The memory location held by iptr2 = " << iptr2 << endl;
    /*
     * This is because `new` allocates memory on the *heap*, not
     * on the stack. Stack memory is automatically allocated by the
     * run-time system, but with heap memory, *you*, the programmer,
     * are in charge. For instance, with heap memory, you can control
     * when it is freed, by calling `delete`:
     * */
    delete iptr2;
    /*
     * You can (because the C++ approach is "if the programmer wants to try
     * this, let them") de-reference that memory, but the result is
     * undefined.
     * */
    cout << "After delete, the value pointed to by iptr2 = "
        << *iptr2 << endl;
    int* iptr3 = new int(14);
    cout << "After new alloc, the value pointed to by iptr2 = "
        << *iptr2 << endl;
    cout << "Value pointed to by iptr3 = " << *iptr3 << endl;
    /*
     * Finally, there is a special pointer value: nullptr.
     * */
    int* iptr4 = nullptr;
    if (!iptr4) cout << "iptr4 is null\n";
    f(7, (byte *) &iptr4);
}

