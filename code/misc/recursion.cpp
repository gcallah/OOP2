
/*
 * Let's work some recursion problems!
 *
 * */
#include <iostream>

#include "base_conv.h"

using namespace std;


int factorial(int n) {
    /*
     * The natural way to do factorials:
     * */
    if (n == 0) return 1;
    return n * factorial(n - 1);
}


int main() {
    for (int i = 0; i < 10; i++)
        cout << i << " factorial = " << factorial(i) << endl;

    for (int i = 0; i < 10; i++)
        cout << i << " in hex: " << base_conv(i) << endl;
}
