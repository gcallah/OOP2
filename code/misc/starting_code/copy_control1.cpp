
/*
 * Copy Control
 * `copy_control.cpp` is designed to illustrate basic memory management.
 * We will use the "big three" of copy control:
 * 1) destructor
 * 2) copy constructor
 * 3) assignment operator
 * */
#include <iostream>
using namespace std;

/*
 * We define a simple structure with a constructor and a single field,
 * which happens to be a pointer.
 * */
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& t);

 public:
    Thing(int i) : iptr(new int(i)) {}

    Thing(const Thing& source) {
        iptr = new int(*source.iptr);
    }

    ~Thing()  {
        cout << "In destructor deleting memory at " << this->iptr << endl;
        delete iptr;
    }

    Thing& operator=(const Thing& source) {
        if (this != &source) {
            delete iptr;
            iptr = new int(*source.iptr);
        }
        return *this;
    }

    int get_val()  { return *iptr; }
    void set_val(int n)  { *iptr = n; }

 private:
    int* iptr;
};


ostream& operator<<(ostream& os, const Thing& t) {
    os << *(t.iptr);
    return os;
}


void g(Thing thing_copy) {
    thing_copy.set_val(17);
}


void f() {
    Thing thing(16);

    cout << thing << endl;
    thing.set_val(32);
    cout << thing << endl;

    g(thing);
}


/*
 * In `main()` we are going to
 * */
int main() {
    // Loop making things:
    // for (int i = 0; i < 2000000000; i++)
    for (int i = 0; i < 4; i++)
        f();
}

