#include <iostream>
using namespace std;

const int DEF_VCAPACITY = 2;

int missing_function(int n);


class MyVec {
 public:
    MyVec() {
        cout << "Longs are " << sizeof(j) << " bytes" << endl;
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new int[DEF_VCAPACITY];
    }

    MyVec(const MyVec& rhs) {
        cout << "Calling copy constructor\n";
        sz = rhs.sz;
        capac = rhs.capac;
        data = new int[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = rhs.data[i];
        }
    }

    ~MyVec() {
        cout << "Calling destructor\n";
        delete [] data;
    }

    MyVec& operator=(const MyVec& rhs) {
        cout << "Calling assignment operator\n";
        if (&rhs != this) {  // check for self-assign!
            delete [] data;
            sz = rhs.sz;
            capac = rhs.capac;
            data = new int[capac];
            for (size_t i = 0; i < sz; i++) {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }

    int operator[](int i) const {
        return data[i];
    }

    void push_back(int val) {
        sz++;
        if (sz == capac) {
            cout << "Increasing capacity\n";
            int* old_data = data;
            capac *= 2;
            data = new int[capac];
            for (size_t i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            delete [] old_data;
        }
        data[sz - 1] = val;
    }

    size_t size() const { return sz; }

    long j;
    const int* begin() const { return data; }
    const int* end()   const { return data + sz; }

 private:
    size_t sz;
    size_t capac;
    int* data;

    void copy(const MyVec& source) {
    }
};


void print_vec(const MyVec& ivec) {
    for (int item : ivec) {
        cout << item << ' ';
    }
//    for (size_t i = 0; i < ivec.size(); i++) {
//        cout << ivec[i] << ' ';
//    }
    cout << endl;
}


int main()
{
    missing_function(7);
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec();
    cout << "Vector memory = " << sizeof(v1) << endl;
    cout << "Vector number elements = " << v1.size() << endl;
    v1.push_back(4);
    v1.push_back(8);
    if (true) {
        MyVec v2 = v1;
        print_vec(v2);
    }
    cout << "v2 out of scope.\n";
//    print_vec(v2);
    v1.push_back(16);
    v1.push_back(32);
    v1.push_back(64);
    v1.push_back(128);
    v1.push_back(256);
    v1.push_back(512);
    v1.push_back(1024);
//    cout << "Vector size = " << sizeof(v1) << endl;
    cout << "Vector number elements = " << v1.size() << endl;
    print_vec(v1);
//


    v1 = v1;
    cout << "Constructing v3\n";
    MyVec v3 = MyVec();
    v3 = v1;
    print_vec(v3);
    print_vec(v1);

//
//    cout << "Done with test!\n";
    return 0;
}
