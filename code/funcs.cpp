#include <iostream>
using namespace std;

void f(int n)
{
    n++;
}


void f1(int& n)
{
    n++;
}


void f2(const int& n)
{
    n++;
}


int main()
{
    cout << "Hello world!\n";
    int n = 7;
    f(n);
    cout << n << endl;
    f1(n);
    cout << n << endl;
}
