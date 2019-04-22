#include <iostream>
using namespace std;

class Base {
    /*
     * Just a trivial base class to explore polymorphism.
     * */
 public:
     /*
      * Trying taking out the keyword 'virtual' and see
      * how your output changes:
      * */
    virtual void show() {
        cout << "Base\n";
    }
};

class Derived : public Base {
    /*
     * Just a trivial derived class to explore polymorphism.
     * */
 public:
    void show() override {
        cout << "Derived\n";
    }
 private:
    int x;
    int y;
};

//void f(Base b) {
void f(Base& b) {
    /*
     * If the param is `Base` we will output 'Base'.
     * On the other hand, if it is `Base&` we get 'Derived.'
     * */
    // cout << "size of b = " << sizeof(*b) << endl;
    b.show();
}

int main() {
    /*
     * Testing calling virtual functions on base copies.
     * */
    Derived d;
    // cout << "size of d = " << sizeof(d) << endl;
    f(d);
}
