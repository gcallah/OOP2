#include <iostream>
#include <map>
#include <string>

#include "base_conv.h"

using namespace std;


string base_conv(int n, int to_base) {
    if (n < to_base) return to_string(n);
    else {
        int digit = n % to_base;
        return to_string(n) + base_conv(n / to_base);
    }
}


