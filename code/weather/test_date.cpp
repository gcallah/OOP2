// Copyright 2019 Gene Callahan
// date_test: test our date class
#include <iostream>
#include <cassert>

#include "date.h"

using namespace std;

int main() {
    /*
     * Run some tests on our date class.
     * */
    Date d1(12, 3, 2000);
    cout << d1 << endl;
    assert(d1.to_string() == "12/3/2000");

    d1.add_months(2);
    cout << d1 << endl;
    assert(d1.to_string() == "3/3/2001");

    d1.add_months(4);
    cout << d1 << endl;
    assert(d1.to_string() == "7/3/2001");

    Date d2(1, 1, 2020);
    cout << d2 << endl;
    assert(d2.to_string() == "1/1/2020");

    d2.add_years(100);
    cout << d2 << endl;
    assert(d2.to_string() == "1/1/2120");
}
