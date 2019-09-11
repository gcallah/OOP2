/*
 * A demo of the problem with globals.
 * */
#include <iostream>
using namespace std;

const int MAX_ADJUST = 4;

int mystery_var = rand() % MAX_ADJUST;

int adjust(int n);
int squarish(int n);


int main() {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        cout << "squarish of " << i << " = " << squarish(i) << endl;
    }
}


int squarish(int n) {
    return adjust(n * n);
}


int adjust(int n) {
    mystery_var = rand() % MAX_ADJUST - (MAX_ADJUST / 2);
    return n + mystery_var;
}
