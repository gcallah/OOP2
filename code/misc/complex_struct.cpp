/*
 *  This file is for taking a struct into a class
 *  for an inclass demo.
 * */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const bool DEBUG = true;

class Complex
{
    friend ostream& operator<<(ostream& os, const Complex& c);

 public:
    Complex() : real(0.0), imaginary(0.0) { }
    Complex(double r, double im) : real(r), imaginary(im) { }
    // Complex(double r=0.0, double im=0.0) : real(r), imaginary(im) { }

    Complex add(const Complex& other)
    {
        Complex result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        return result;
    }
    double get_real() const { return real; }
    double get_imaginary() const { return imaginary; }

    void set_real(double r) { real = r; }
    void set_imaginary(double r) { imaginary = r; }

 private:
    double real;
    double imaginary;
};


ostream& operator<<(ostream& os, const Complex& c) {
    os << setprecision(10) << "R: " << c.real << " I: " 
         << c.imaginary;
    return os;
}


void readVector(istream& is, vector<Complex>&);

void printVector(ostream& os, const vector<Complex>& v);


int main()
{
    // A program to introduce `struct`.
    // We will work with complex numbers.
    Complex c1;
    cout << c1 << endl;
    cout << "\nInput a complex number:\n";
    double r, i;
    cin >> r >> i;
    if(!cin)
    {
        cerr << "Bad input format\n";
        exit(1);
    }
    c1.set_real(r); c1.set_imaginary(i);
    if(DEBUG)
    {
        cout << "c1 = " << c1 << endl;
    }

    Complex c2{43.2, 58.9};

    Complex c3 = c1.add(c2);
    cout << c3 << endl;

    vector<Complex> v;
    ifstream ifs("complex.txt");
    readVector(ifs, v);

    cout << "Printing vector\n";
    printVector(cout, v);
}


void printVector(ostream& os, const vector<Complex>& v)
{
    for(const Complex& c : v)
    {
        os << c << "; " << endl;
    }
    os << endl;
}


void readVector(istream& is, vector<Complex>& v) {
    double r, im;
    while (is >> r >> im) {
        Complex c(r, im);
        v.push_back(c);
    }
}

