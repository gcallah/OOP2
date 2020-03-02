#include <iostream>
using namespace std;

const int DEF_VCAPACITY = 2;


class MyVec {
 public:
    MyVec() {
    }

    MyVec(const MyVec& source) {
        cout << "Calling copy constructor\n";
    }

    ~MyVec() {
        cout << "Calling destructor\n";
    }

    MyVec& operator=(const MyVec& source) {
        cout << "Calling assignment operator\n";
    }

    int operator[](int i) const {
    }

    void push_back(int val) {
    }

    size_t size() const { return sz; }

 private:
    size_t sz;

    void copy(const MyVec& source) {
};


// void print_vec(MyVec ivec) {
void print_vec(const MyVec& ivec) {
    for (size_t i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << ' ';
    }
    cout << endl;
}


int main()
{
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec();
//    cout << "Vector size = " << sizeof(v1) << endl;
//    v1.push_back(4);
//    v1.push_back(8);
//    v1.push_back(16);
//    v1.push_back(32);
//    v1.push_back(64);
//    cout << "Vector size = " << sizeof(v1) << endl;
//    print_vec(v1);
//
//    cout << "Constructing v2\n";
//    MyVec v2 = v1;
//
//    cout << "Constructing v3\n";
//    MyVec v3 = MyVec();
//    v3 = v1;
//    
//    cout << "Size of v3 is: " << v3.size() << endl;
//
//    print_vec(v2);
//    print_vec(v3);
//
//    /*
//    */
//
//    cout << "Done with test!\n";
    return 0;
}
