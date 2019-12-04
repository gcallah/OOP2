/*
 * This program determines the representation of an integer in any base
 * between 2 and 26. It could easily be extended to include higher bases.
 * */
#include <iostream>
#include <string>

using namespace std;

char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


string num_to_baseX(int num, int base) {
    string s;
    cout << "Converting " << num << " to base " << base << endl;
    s += digits[num % base];  // strip off from the back
    string rest;
    if (num >= base)
        rest = num_to_baseX(num / base, base);
    return rest + s;
}


int main() {
    int num, base;
    cout << "Enter a number to convert: \n";
    cin >> num;
    cout << "Enter a base to convert to: \n";
    cin >> base;
    string result = num_to_baseX(num, base);
    cout << result << endl;
}
