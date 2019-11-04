/*
 * Code from John Sterling.
  6.hidingA.cpp
  der.foo(17) calls Base::foo(int) through code reuse, i.e. method inheritance
  Inclass C
 */

#include <iostream>
using namespace std;

class Base {
public:
    void foo(int n) const { cout << "Base::foo(n)\n"; }
};

class Derived : public Base { 
public:
    void foo() const { cout << "Foo::foo()\n"; }
    //    void foo(int n) const { cout << "Base::foo(n)\n"; }
    //    void foo(int n) const { Base::foo(n); }
    using Base::foo;
};

int main() {
    Derived der;
    der.foo(17);
    //der.Base::foo(17);
}

