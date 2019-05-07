#include <iostream>
#include <string>

#include "base_conv.h"

using namespace std;

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};


string base_conv(int n, int to_base) {
    if (n < to_base) return string(1, digits[n]);
    else {
        int digit = n % to_base;
        return base_conv(n / to_base, to_base)
            + string(1, digits[digit]);
    }
}


