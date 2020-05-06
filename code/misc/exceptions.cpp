
/*
 * A study of some aspects of C++ error handling, 
 * focused on exceptions with a sprinkling of assertions
 * and error code returns.
 * */

#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;


/*
 * We should always give our constants symbolic names,
 * so we can change them in one place: don't repeat yourself!
 * */
const int MAX_TEMP = 90;  // can't set thermostat higher

/*
 * `TempTooHigh`:
 * an exception to throw when we get a temperature 
 * out of any reasonable range.
 * Its constructor collects some relevant information
 * about the problem that occurred that can be shared
 * with the user.
 * */
class TempTooHigh : public exception {
public:
    TempTooHigh(int n, int line, string file) 
        : too_high(n), line_num(line), file_name(file)
    {
    }

    const char* what() const throw() {
        return " is too high a temperature";
    }

    int high_temp() const { return too_high; }
    int which_line() const { return line_num; }
    string which_file() const { return file_name; }

private:
    int too_high;
    int line_num;
    string file_name;
};


/*
 * `set_thermostat()` throws TempTooHigh when n &gt; MAX_TEMP.
 * */
void set_thermostat(int n) {
    if (n > MAX_TEMP) throw(TempTooHigh(n, 57, "exceptions.cpp"));
}


/*
 * `set_temp()` calls `set_thermostat()`.
 * The only purpose of this intermediate call is
 * to show how exceptions rise up the stack.
 * */
void set_temp(int n) {
    set_thermostat(n);
}


/*
 * This function will throw an exception because `vector.at()`
 * does range checking.
 * */
void h(int n) {
    vector<int> v = vector<int>(n, -1);
    cout << v.at(n) << endl;
}


/*
 * The get_records() call returns error codes, for comparison.
 * */
int get_records() {
    /*
     * We imagine here we make some database access,
     * that returns a number of records, or an error code.
     * */
    return rand();
}

/*
 * `main()` will call some functions that throw exceptions,
 * and use an assertion.
 * */
int main() {
    int n = MAX_TEMP + 1;

    /*
     * The following is the sort of code that we get when we have
     * error code returns.
     * */
    int ret_code = get_records();
    if (ret_code == -1)
        cout << "database not available\n";
    else if (ret_code == -2)
        cout << "No records present\n";
    else
        cout << "Proceeding to process records\n";

    try {
        set_temp(n);
    }
    catch (TempTooHigh& too_high) {
        cerr << "Temperature error: "
            << too_high.high_temp() << too_high.what()
            << " at line " << too_high.which_line()
            << " in file " << too_high.which_file() << endl;
    }

    /*
     * Next we will illustrate catching *any* exception
     * that inherits from `std::exception`.
     * */
    try {
        h(100);
    }
    catch (exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    /*
     * The point of the output that follows is to demonstrate
     * that our exceptions, *when caught*, do *not* terminate
     * the program.
     * */
    cout << "Still in main()!\n";

    /*
     * Finally, we just illustrate how `assert(cond)`
     * is used.
     * */
    assert(n <= 1000);
}
