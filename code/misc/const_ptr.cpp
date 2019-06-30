#include <iostream>

using namespace std;


/*
 * This function is fine, because we have a constant pointer to an int
 * (that may change).
 * */
void foo(int x) { 
    int* const p = &x; // line A
    x = 17; // line B
    cout << *p << ' '; // line C
    *p = 28; // line D 
}


/*
 * This next function won't compile, because we have a pointer to
 * a constant int.
 * */
//void foo1(int x) { 
//    int const * p = &x; // line A
//    x = 17; // line B
//    cout << *p << ' '; // line C
//    *p = 28; // line D 
//}


int main() { 
    int y = 42;
    foo(y);
    cout << y << endl;
}

