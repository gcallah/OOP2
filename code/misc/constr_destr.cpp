
#include <iostream>
#include <vector>

using namespace std;


class A {
    public:
        A(int a0) : a(a0) { cout << "Constructing A\n"; }
        ~A() { cout << "Destructing A; a == " << a << "\n"; }

        // copy constructor:
        A(const A& other) {
            cout << "In A's copy constructor.\n";
            a = other.a;
        }
        int my_int() { return a; }
        // virtual int my_int() { return a; }
    private:
        int a;
};

class B : public A {
    public:
        B() : A(2), b(4) { cout << "Constructing B\n"; }
        ~B() { cout << "Destructing B\n"; }

        // copy constructor:
        B(const B& other) : A(other) {
            cout << "In B's copy constructor.\n";
            b = other.b;
        }
        int my_int() { return b; }
        // virtual int my_int() { return b; }
    private:
        int b;
};

class C : public B {
    public:
        C() : c(8) { cout << "Constructing C\n"; }
        ~C() { cout << "Destructing C\n"; }

        // copy constructor:
        C(const C& other) {
            cout << "In C's copy constructor.\n";
            c = other.c;
        }

        int my_int() { return c; }
        // virtual int my_int() { return c; }
    private:
        int c;
};

int main() {
    A a = A(2);
    B b = B();
    C c = C();
    cout << "A size = " << sizeof(A) << endl;
    cout << "B size = " << sizeof(B) << endl;
    cout << "C size = " << sizeof(C) << endl;

    C c2 = c;

    A a2 = c;
    cout << "a2 size = " << sizeof(a2) << endl;

    vector<A*> v;
    v.push_back(&a);
    v.push_back(&b);
    v.push_back(&c);

    for (A* aptr : v) {
        cout << "int: " << aptr->my_int() << endl;
    }
}

