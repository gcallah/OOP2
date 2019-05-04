#include <iostream>

using namespace std;


class Member {
public:
    Member()  {cout << 'e';}
    ~Member() {cout << 'f';}
};

class Base {
    Member member;
public:
    Base()  {cout << 'c';}
    ~Base() {cout << 'd';}
};

class Derived : public Base {
public:
    Derived()  {cout << 'a';}
    ~Derived() {cout << 'b';}
};


int main() {
    Derived der;
}

