
/*
 * This code will convert integers into any base from 2 to MAX_BASE.
 * */
#include <iostream>
#include <string>

#include "base_conv.h"

using namespace std;

const int MIN_BASE = 2;
const int MAX_BASE = 62;


/*
 * A table in which we can look up the digits for our base-N
 * number:
 * */
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
                 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                 'Y', 'Z'
};


/*
 * The recursive code which strips off the digits from back-to-front
 * using modulus and integer division:
 * */
string base_conv(int n, int to_base) {
    if (to_base < MIN_BASE || to_base > MAX_BASE) return "BAD BASE; 2 <= base <= 62";

    if (n < to_base) return string(1, digits[n]);
    else {
        int digit = n % to_base;
        return base_conv(n / to_base, to_base)
            + string(1, digits[digit]);
    }
}


int main() {
    int num, base;
    cout << "Enter a number: ";
    cin >> num;
    cout << "\nEnter a base: ";
    cin >> base;
    string answer = base_conv(num, base);
    cout << "\n" << num << " in base " << base << " = " << answer << endl;
}
