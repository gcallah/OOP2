/*
 * This file explores different ways to pass an arg to a function in C++:
 * *pass by value*
 * *pass by reference*
 * *pass by constant reference*
 * It also illustrates the use of a return value from a function.
 * */
#include <iostream>
#include <vector>
using namespace std;

const bool DEBUG = true;


/*
 * Function prototypes just state the return value type,
 * the function name, and the parameter types.
 * */
void pass_by_value(int n);
void pass_by_ref(int& n);
int call_with_ret(int n);


int main() {
    int n = 7;
    pass_by_value(n);
    cout << "after pass_by_value, n = " << n << endl;

    pass_by_ref(n);
    cout << "after pass_by_ref, n = " << n << endl;

    int n2 = call_with_ret(n);
    cout << "after call_with_ret, n2 = " << n2 << endl;
    cout << "The square of " << n << " is " << n2 << endl;
}

void pass_by_value(int n) {
    /*
     * Demonstrate passing by value.
     * */
    n++;
}


void pass_by_ref(int& n) {
    /*
     * Demonstrate passing by reference.
     * */
    n++;
}


int call_with_ret(int n) {
    /*
     * Using a function's return value.
     * */
    return(n * n);
}


/*
 * Uncomment the following function, and you will find it will
 *
 * not compile: if `n` is const, we can't modify it!
 * */
// void pass_by_constref(const int& n)
// {
//    n++;
// }


