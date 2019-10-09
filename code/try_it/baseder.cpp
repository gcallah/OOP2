#include <iostream>

using namespace std;


class Base {
public:
    void display() {
        cout << "Base ";
    }    
};

class Derived: public Base {
public:
    virtual void display() {
        cout << "Derived ";
    }    
};

void display_class(Base& b) {
    b.display();
}

int main() {
    Base b;
    Derived d;
    display_class(b);
    display_class(d);
}

