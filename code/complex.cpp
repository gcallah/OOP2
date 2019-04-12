/*
 * FILE: complex.cpp
 * THEME: operator over-loading.
 * CLASSES: Complex
 * */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const bool DEBUG = true;

class Complex {
    /*
     * A partial implementation of a complex number class,
     * designed to illustrate operator over-loading.
     * */
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend istream& operator>> (istream& is, Complex& c);

    friend bool operator== (const Complex& c1, const Complex& c2) {
        /*
         * The equality operator is a friend since it is binary
         * and symmetrical.
         * */
        return ((c1.real == c2.real) && (c1.imag == c2.imag));
    }

    public:
    
        Complex(double real=0.0, double imag=0.0)
            : real{real}, imag{imag} {}

        explicit operator bool() const {
            /*
             * The `bool` operator tests to see if either
             * data member is non-zero, and returns `true`
             * if so.
             * */
            return ((real != 0) || (imag != 0));
        }

        Complex& operator++() {
            /*
             * This overload is pre-increment: pretty straightforward:
             * bump up the `real` member, and return myself.
             * Of course, it's not obvious that this is what incrementing
             * a complex number *should* do: but we are teaching here,
             * not writing a production Complex class.
             * */
            ++real;
            return (*this);
        }

        Complex operator++(int dummy) {
            /*
             * Post-increment is more complicated than pre: first
             * of all, it takes a dummy int parameter (unused)
             * just so the compiler can tell which inc operator is which.
             * Secondly, since it returns the value from *before*
             * the increment, we must store that in a temp var.
             * */
            Complex temp(*this);
            real++;
            return temp;
        }

        Complex operator+(const Complex& c) {
            /*
             * `+` is very straightforward, and should be the first operator
             * taught.
             * */
            Complex sum{real + c.real, imag + c.imag};
            return sum;
        }

    private:
        double real;
        double imag;
};


ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(10) << c.real << showpos 
         << c.imag << "i" << noshowpos << endl;
    return os;
}


istream& operator>> (istream& is, Complex& c) {
    /*
     * Read a `Complex` number from an input stream.
     * */
    is >> c.real >> c.imag;
    return is;
}


void printVector(const vector<Complex>& v);


int main() {
    /*
     * The code in main just exercizes the `Complex` class.
     * */
    cout << "Input a complex number:\n";
    Complex c1;
    // get a complex from stdin:
    cin >> c1;
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

    Complex c4 = Complex();
    // test post-increment:
    c4++;
    // test bool():
    (1 == c4) ? cout << "c4 == 1 is true\n" 
        : cout << "c4 == 1 is false\n";

    vector<Complex> v{c1, c2, c3, c4};
    cout << "Printing vector\n";
    printVector(v);
}


void printVector(const vector<Complex>& v)
{
    // auto detects the type coming from the vector automatically:
    for(auto c : v) {
        cout << c;
    }
}

