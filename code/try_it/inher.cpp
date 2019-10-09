#include <iostream>

class A {
public:
    A() {
        std::cout << "A ";
    }    
};

class B {
public:
    B() {
        std::cout << "B ";
    }    
    
};

class C: public B {
public:
    C(){
        std::cout << "C ";
    }    
    
private:
    A a;
};

class D: public C {
public:
    D() {
        std::cout << "D ";
    }    
    
};

int main() {
	D d;
}

