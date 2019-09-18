/*
 *  This file is for taking a struct into a class
 *  for an inclass demo.
 * */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const bool DEBUG = true;

class Complex
{
 public:
    Complex(double r=0.0, double im=0.0) : real(r), imaginary(im) { }

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


void printVector(const vector<Complex>& v);
void printComplex(const Complex& c);


int main()
{
    // A program to introduce `struct`.
    // We will work with complex numbers.
    Complex c1;
    printComplex(c1);
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
        cout << "c1 = ";
        printComplex(c1);
    }

    /*
    Complex c2{43.2, 58.9};
    if(DEBUG) 
    {
        cout << "c2 = ";
        printComplex(c2);
    }

    Complex c3 = c1.add(c2);
    printComplex(c3);

    vector<Complex> v{c1, c2, c3};
    cout << "Printing vector\n";
    printVector(v);
    */
}


void printComplex(const Complex& c)
{
    cout << setprecision(10) << "R: " << c.get_real() << " I: " 
         << c.get_imaginary() << endl;
}


void printVector(const vector<Complex>& v)
{
    for(auto c : v)
    {
        printComplex(c);
    }
}

