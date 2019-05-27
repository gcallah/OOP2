
/*
 * A study of some aspects of C++ exception handling.
 * */

#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdlib.h>
using namespace std;


/*
 * An exception to throw when we get a number too big.
 * */
class NTooBig : public exception {
public:
    NTooBig(int n, int line, string file) 
        : too_big(n), line_num(line), file_name(file)
    {
    }

    const char* what() const throw() {
        char tb[12] = itoa(too_big, tb);
        return "N is too big: ";
    }

private:
    int too_big;
    int line_num;
    string file_name;
};


/*
 * Throw NTooBig when n > 200.
 * */
void f(int n) {
    if (n > 200) throw(NTooBig(n, 31, "exceptions.cpp"));
}


/*
 * Call `f()`: just showing how exceptions rise up the stack.
 * */
void g(int n) {
    f(n);
}


void h(int n) {
    vector<int> v = vector<int>(n, -1);
    cout << v.at(n) << endl;
}

/*
 * `main()` will call some functions that throw exceptions.
 * */
int main() {

    int n = 201;

    assert(n <= 200);

    try {
        // h(16);
        g(n);
    }
    catch (NTooBig& e) {
        cerr << "Got a number too big for f(): "
            << e.what() << endl;
    }
    catch (exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    cout << "Still in main()!\n";
}
