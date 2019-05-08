
/*
 * A study of some aspects of C++ exception handling.
 * */

#include <exception>
#include <iostream>
#include <vector>
using namespace std;


void f(int n) {
    if (n > 200) throw(n);
}


void g(int n) {
    f(n);
}


void h(int n) {
    vector<int> v = vector<int>(n, -1);
    cout << v[n] << endl;
}

/*
 * `main()` will call some functions that throw exceptions.
 * */
int main() {

    try {
        h(20);
        g(201);
    }
    catch(exception e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    cout << "Still in main()!\n";
}
