
/*
 * Let's work some *recursion* problems!
 *
 * */
#include <iostream>
#include <vector>
#include <climits>

#include "base_conv.h"

using namespace std;


/*
 * Test max stack depth with infinite recursion.
 * */
int recurse(int n) {
    cout << "In call #: " << n << endl;
    return recurse(n + 1);
}


/*
 * The natural way to do factorials:
 * */
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}


/*
 * Let's create a naive, recursive way to calculate the
 * Fibonacci numbers. This will be *very* slow as `n` gets
 * up to 40 or 50! That is because this way of proceeding has
 * over-lapping subproblems.
 * */
int naive_fib(n) {
    if (n == 0 || n == 1) return 1;
    else return fib(n - 1) + fib(n - 2);
}


/*
 * But we can *memo-ize* a recursive fibonacci call.
 * Memo-ization means storing results rather than re-calculating
 * them every time they are required.
 * This version will run *much* faster than the previous one.
 * */
const int NOT_CALCULATED = -1;
vector<int> fib_memos = vector<int>(100, NOT_CALCULATED);

int fib(int n) {
    if (fib_memos[n] == NOT_CALCULATED) {
        int ret = 0;
        if (n == 0 || n == 1) ret = 1;
        else ret = fib(n - 1) + fib(n - 2);
        fib_memos[n] = ret;
        return ret;
    }
    else return fib_memos[n];
}


/*
 * *Towers of Hanoi*, recursive style.
 * We both count moves and print to check our algorithm.
 * */
void towers(int n, int& moves,
            int start=0, int target=1, int spare=2) {
    if (n > 1) towers(n - 1, moves, start, spare, target);
    moves++;
    cout << "Moving disk " << n << " to peg " << target << endl;
    if (n > 1) towers(n - 1, moves, spare, target, start);
}


/*
 * Our `main()` will exercise the above functions.
 * */
int main() {
    const int DISKS = 4;
    int moves = 0;
    towers(DISKS, moves);
    cout << "For " << DISKS << " we made " << moves << " moves\n\n";

    // This is an infinite recursion:
    // recurse(INT_MAX);

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
