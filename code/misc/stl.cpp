/*
 * Let's use the Standard Template Library!
 * */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


int main() {
    /*
     * Tests for STL code usage.
     * */
    char s[] = "Bjarne Stroustrup";

    cout << s << "\n";

    int len = 17;
    sort(s, s + len);

    cout << s << "\n";
}
