#include <iostream>
#include <string>
using namespace std;

const int DEF_VCAPACITY = 2;
const int EXTRA_CAPACITY = 2;


class MyVec {
 public:
    MyVec() {
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new int[DEF_VCAPACITY];
    }

    explicit MyVec(size_t items, int init_val=0) {
        sz = items;
        capac = items * EXTRA_CAPACITY;
        data = new int[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = init_val;
        }
    }

    MyVec(const MyVec& source) {
        cout << "Calling copy constructor\n";
        copy(source);
    }

    ~MyVec() {
        cout << "Calling destructor\n";
        delete [] data;
    }

    MyVec& operator=(const MyVec& source) {
        cout << "Calling assignment operator\n";
        if (this != &source) {
            delete [] data;
            copy(source);
        }
        return *this;
    }

    int& operator[](int i) {
        return data[i];
    }

    int operator[](int i) const {
        return data[i];
    }

    const int* begin() const {
        return data;
    }

    const int* end() const {
        return data + sz;
    }

    int* begin() { return data; }

    int* end() { return data + sz; }

    void clear() {
        sz = 0;
    }

    int back() const { return data[sz - 1]; }
    int& back() { return data[sz - 1]; }

    void pop_back() {
        if (sz > 0) sz--;
    }

    void push_back(int val) {
        sz++;
        if (sz == capac) {  // we're about to up it!
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new int[capac * EXTRA_CAPACITY];
            for (size_t i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capac *= EXTRA_CAPACITY;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }

    size_t size() const { return sz; }

 private:
    size_t sz;
    size_t capac;
    int* data;

    void copy(const MyVec& source) {
        sz = source.sz;
        capac = source.capac;
        data = new int[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = source.data[i];
        }
    }
};


double deref(double* dptr) {
    return *dptr;
}


void print_vec(const MyVec& ivec, const string& msg) {
    cout << "\n**************\n" << msg << endl;
    for (int item : ivec) {
        cout << item << ' ';
    }
    cout << "\n**************\n";
}


int main()
{
    /*
    cout << "sizeof size_t = " << sizeof(size_t) << endl;
    cout << "sizeof long = " << sizeof(long) << endl;
    cout << "sizeof int = " << sizeof(int) << endl;
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec();
    cout << "Vector size = " << sizeof(v1) << endl;
    v1.push_back(4);
    v1.push_back(8);
    v1.push_back(16);
    v1.push_back(32);
    v1.push_back(64);
    cout << "Vector size = " << sizeof(v1) << endl;
    print_vec(v1, "v1 contains:");

    cout << "Constructing v2\n";
    MyVec v2 = v1;
    v2[0] = 7;

    cout << "Constructing v3\n";
    MyVec v3 = MyVec();
    v3 = v1;
    
    cout << "Size of v3 is: " << v3.size() << endl;

    print_vec(v2, "v2 contains:");
    print_vec(v3, "v3 contains:");

    v2.pop_back();
    for (int& item : v2) {
        item *= 2;
    }

    v3.clear();
    print_vec(v2, "v2 contains:");
    print_vec(v3, "v3 contains:");
    */

    // int not_dbl = 7;
    double dbl = 7.0;

    cout << "deref = " << deref(&dbl) << endl;

    MyVec v4(10, 7);
    print_vec(v4, "before v4 contains:");
    v4 = MyVec(9);
    cout << "v4 last elem = " << v4.back() << endl;
    print_vec(v4, "after v4 contains:");

    cout << "Done with test!\n";
    return 0;
}
