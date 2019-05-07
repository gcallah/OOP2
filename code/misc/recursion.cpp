
/*
 * Let's work some recursion problems!
 *
 * */
#include <iostream>
#include <vector>
#include <climits>

#include "base_conv.h"

using namespace std;


int recurse(int n) {
    /*
     * Test max stack depth with infinite recursion.
     * */
    cout << "In call #: " << n << endl;
    return recurse(n + 1);
}


int factorial(int n) {
    /*
     * The natural way to do factorials:
     * We haven't done any 
     * */
    if (n == 0) return 1;
    return n * factorial(n - 1);
}





vector<int> fib_memos = vector<int>(100, -1);

int fib(int n) {
    if (fib_memos[n] == -1) {
        int ret = 0;
        if (n == 0 || n == 1) ret = 1;
        else ret = fib(n - 1) + fib(n - 2);
        fib_memos[n] = ret;
        return ret;
    }
    else return fib_memos[n];
}


void towers(int n, int start = 0, int target = 1, int spare = 2) {
    if (n > 1) towers(n - 1, start, spare, target);
    cout << "Moving disk " << n << " to peg " << target << endl;
    if (n > 1) towers(n - 1, spare, target, start);
}


int main() {
    towers(3);

    // recurse(INT_MAX - 4);

    int big_num = INT_MAX - 4;
    for(int i = 0; i < 20; i++) {
        cout << "big_num = " << big_num++ << endl;
    }

    for (int i = 0; i < 8; i++)
        cout << i << " factorial = " << factorial(i) << endl;
    for (int i = 0; i < 5; i++)
        cout << i << " fibonacci = " << fib(i) << endl;


    for (int i = 0; i < 40; i++)
        cout << i << " in binary: " << base_conv(i, 2) << endl;

    for (int i = 0; i < 40; i++)
        cout << i << " in hex: " << base_conv(i) << endl;

    for (int i = 0; i < 40; i++)
        cout << i << " in oct: " << base_conv(i, OCT) << endl;

    for (int i = 0; i < 40; i++)
        cout << i << " in base-20: " << base_conv(i, 20) << endl;
}
