
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
        return " is too big";
    }

    int bad_number() const { return too_big; }
    int which_line() const { return line_num; }
    string which_file() const { return file_name; }

private:
    int too_big;
    int line_num;
    string file_name;
};


/*
 * Throw NTooBig when n > 200.
 * */
void f(int n) {
    if (n > 200) throw(NTooBig(n, 42, "exceptions.cpp"));
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

    try {
        // h(16);
        g(n);
    }
    catch (NTooBig& e) {
        cerr << "Got a number too big for f(): "
            << e.bad_number() << e.what()
            << " at line " << e.which_line()
            << " in file " << e.which_file() << endl;
    }
    catch (exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    cout << "Still in main()!\n";

    assert(n <= 1000);
}
