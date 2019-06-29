
#include <iostream>

using namespace std;


class A {
    public:
        A(int a0) : a(a0) { cout << "Constructing A\n"; }
        ~A() { cout << "Destructing A; a == " << a << "\n"; }
        int a;
};

class B : public A {
    public:
        B() : A(12), b(0) { cout << "Constructing B\n"; }
        ~B() { cout << "Destructing B\n"; }
        int b;
};

class C : public B {
    public:
        C() : c(0) { cout << "Constructing C\n"; }
        ~C() { cout << "Destructing C\n"; }
        int c;
};

int main() {
 //   A a = A(2);
    B b = B();
    C c = C();
//    cout << "A size = " << sizeof(A) << endl;
    cout << "B size = " << sizeof(B) << endl;
    cout << "C size = " << sizeof(C) << endl;
}

