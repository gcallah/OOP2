/*
 * This program determines the representation of an integer in any base
 * between 2 and 36. It could easily be extended to include higher bases,
 * by adding to the string `digits`.
 * */
#include <iostream>
#include <string>

using namespace std;

/*
 * The following string gives us up to 36 digits: just add more
 * characters and you can handle larger bases. An obvious first move
 * would be to add lower case letters. One could then continue with punctuation
 * marks.
 * */
char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


/*
 * Our recursive procedure is to strip a number off the back
 * of `num` by modding it with the base, and then make a recursive
 * call that processes the rest of the number, by passing in
 * `num / base`.
 * */
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
    cout << "Enter a number (in base 10!) to convert: \n";
    cin >> num;
    cout << "Enter a base to convert to: \n";
    cin >> base;
    string result = num_to_baseX(num, base);
    cout << result << endl;
}
