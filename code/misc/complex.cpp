/*
 * This file implements part of a complex number class.
 * Its chief educational purpose is to teach *operator overloading*.
 * We want to implement:
 * pre-increment
 * post-increment
 * bool
 * +
 * +=
 * ==
 * !=
 * Further overloads can be left for the student.
 * */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const bool DEBUG = true;

class Complex {
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend istream& operator>> (istream& is, Complex& c);
    friend Complex operator+ (const Complex& c1,
            const Complex& c2) {
        Complex sum(c1.real + c2.real, c1.imag + c2.imag);
        return sum;
    }
    friend bool operator==(const Complex& rhs, const Complex& lhs) {
        return ((rhs.real == lhs.real) && (rhs.imag == lhs.imag));
    }

    public:
    
    /*
     * Our sole constructor takes defaults of 0 for both `real` and 
     * `imag`, so can be called with no arguments.
     * */
        Complex(double real=0.0, double imag=0.0)
            : real{real}, imag{imag} {}

        /*
         * pre-increment:
         * */
        Complex& operator++() {
            ++real;
            // return ourselves to allow `x = ++y;`
            return (*this);
        }

        /*
         * post-increment:
         * */
        Complex operator++(int dummy) {
            Complex temp(*this);
            real++;
            return temp;
        }

        explicit operator bool() const {
            return ((real != 0) || (imag != 0));
        }

    private:
        double real;
        double imag;
};


bool operator!=(const Complex& rhs, const Complex& lhs) {
    return ! (rhs == lhs);
}


ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(10) << c.real << showpos 
         << c.imag << "i" << noshowpos;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}


void printVector(const vector<Complex>& v);


/*
 * The code in main just exercizes the `Complex` class.
 * */
int main() {
    cout << "Enter a complex number:\n";
    Complex c1{10, 10};
    // get a complex from stdin:
    // but not when testing!
    // cin >> c1;
    if(!cin)
    {
        cerr << "Bad input format\n";
        exit(1);
    }
    if(DEBUG)
    {
        cout << "c1 = " << c1 << endl;
    }

    Complex c2{43.2, 58.9};
    if(DEBUG) 
    {
        cout << "c2 = " << c2 << endl;
    }

    // see if `Complex` addition works:
    Complex c3 = c1 + c2;
    cout << "c3 = " << c3 << endl;
    // Complex c3;

    Complex c4 = Complex();
    cout << "c4 = " << c4 << endl;
    if (!c4) { cout << "c4 is false\n"; }

    // test post-increment:
    c4++;
    cout << "c4 = " << c4 << endl;
    if (c4) { cout << "c4 is true\n"; }
    cout << "c4 == c3 ? " << (c4 == c3) << endl;
    cout << "c4 == c4 ? " << (c4 == c4) << endl;
    cout << "c4 != c3 ? " << (c4 != c3) << endl;

    // c4++;
//     * Test equality operator. If we take the `explicit` off of
//     * `bool()` in class definition, then this will fail as ambiguous:
//     * the compiler won't know if we want a `bool` or `Complex` comparison.
    if(1 == c4) cout << "c4 == 1 is true\n";
//        : cout << "c4 == 1 is false\n";
//    // test bool() operator:
//    (c4) ? cout << "c4 is true\n" : cout << "c4 is false\n";

    /*
    *
     * The next line of code will implicitly
     * construct a `Complex` out of 14.2 using the default
     * imaginary component of 0.0.
     * */
    Complex c5 = 14.2;

    vector<Complex> v{c1, c2, c3, c4, c5};
    // cout << "Printing vector\n";
    // printVector(v);
}


/*
 * Print a vector of type `Complex`: templates haven't been taught yet!
 * */
void printVector(const vector<Complex>& v)
{
    /*
     * `auto` detects the type coming out of the `vector` automatically:
     * */
    for(auto c : v) {
        cout << c;
    }
}


