// Creating a new type using struct:
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const bool DEBUG = true;

class Complex
{
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend istream& operator>> (istream& is, Complex& c);

    public:
    
        Complex(double real=0.0, double imag=0.0) : real{real}, imag{imag}
        {}

        // we will write:
        // +=, ==, *=, *, -, -=, /, /=
        // bool()
        // we will re-write +

        Complex operator+(const Complex& c)
        {
            Complex sum{real + c.real, imag + c.imag};
            return sum;
        }

    private:
        double real;
        double imag;
};


ostream& operator<< (ostream& os, const Complex& c)
{
    os << setprecision(10) << c.real << showpos 
         << c.imag << "i" << noshowpos << endl;
    return os;
}


istream& operator>> (istream& is, Complex& c)
{
    is >> c.real >> c.imag;
    return is;
}


void printVector(const vector<Complex>& v);


int main()
{
    cout << "Input a complex number:\n";
    Complex c1;
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

    Complex c3 = c1 + c2;
    Complex c4 = 1;

    vector<Complex> v{c1, c2, c3, c4};
    cout << "Printing vector\n";
    printVector(v);
}



void printVector(const vector<Complex>& v)
{
    for(auto c : v)
    {
        cout << c;
    }
}

