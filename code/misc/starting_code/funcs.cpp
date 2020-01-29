/*
 * This file explores different ways to pass an arg to a function in C++:
 * * pass by value
 * * pass by reference
 * * pass by constant reference
 * It also illustrates the use of a return value from a function.
 * */
#include <iostream>
using namespace std;

const bool DEBUG = false;

void pass_by_value(int n);
void pass_by_ref(int &n);
int call_with_ret(int n);
void pass_by_constref(const int& n);


int main() {
    int n = 7;
    pass_by_value(n);
    if(DEBUG)
        cout << "after pass_by_value, n = " << n << endl;
    pass_by_ref(n);
    if(DEBUG)
        cout << "after pass_by_ref, n = " << n << endl;
    int n2 = call_with_ret(n);
    if(DEBUG)
        cout << "after call_with_ret, n2 = " << n2 << endl;
    cout << "The square of " << n << " is " << n2 << endl;
}

/*
 * Demonstrate passing by value.
 * */
void pass_by_value(int n) {
    n++;
}


/*
 * Demonstrate passing by reference.
 * */
void pass_by_ref(int& n) {
    n++;
}


/*
* Using a function's return value.
* */
int call_with_ret(int n) {
    return(n * n);
}


/*
 * Uncomment the following function, and you will find it will
 * not compile: if `n` is const, we can't modify it!
 * */
// void pass_by_constref(const int& n)
// {
//    n++;
// }

