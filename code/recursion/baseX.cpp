/*
 * This program determines the representation of an integer in any base
 * between 2 and 26. It could easily be extended to include higher bases.
 * */
#include <iostream>
using namespace std;


int main() {
    int num, base;
    cout << "Enter a number to convert: \n";
    cin >> num;
    cout << "Enter a base to convert to: \n";
    cin >> base;
    cout << "Converting " << num << " to base " << base << endl;
}
