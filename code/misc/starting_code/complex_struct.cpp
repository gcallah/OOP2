/*
 * Creating a new type using class.
 * This is just an intermediate in-class version.
 * */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const bool DEBUG = true;

struct Complex
{
    double real;
    double imaginary;
};


void printVector(const vector<Complex>& v);
void printComplex(const Complex& c);
Complex add(const Complex& c1, const Complex& c2);


int main()
{
    // A program to introduce `struct`.
    // We will work with complex numbers.
    cout << "Input a complex number:\n";
    Complex c1;
    cin >> c1.real >> c1.imaginary;
    if(!cin)
    {
        cerr << "Bad input format\n";
        exit(1);
    }
    if(DEBUG)
    {
        cout << "c1 = ";
        printComplex(c1);
    }

    Complex c2{43.2, 58.9};
    if(DEBUG) 
    {
        cout << "c2 = ";
        printComplex(c2);
    }

    Complex c3 = add(c1, c2);
    printComplex(c3);

    vector<Complex> v{c1, c2, c3};
    cout << "Printing vector\n";
    printVector(v);
}


void printComplex(const Complex& c)
{
    cout << setprecision(10) << "R: " << c.real << " I: " 
         << c.imaginary << endl;
}


void printVector(const vector<Complex>& v)
{
    for(auto c : v)
    {
        printComplex(c);
    }
}


Complex add(const Complex& c1, const Complex& c2)
{
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

