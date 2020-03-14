#include <iostream>
#include <string>
using namespace std;

const int DEF_VCAPACITY = 2;


class MyVec {
 public:
    MyVec(string nm) : sz(0), capac(DEF_VCAPACITY), name(nm) {
        data = new int[DEF_VCAPACITY];
    }

    explicit MyVec(size_t s, int val=0) : sz(s), capac(s * 2),
                    name("built with constructor2") {
        data = new int[capac];
        for (size_t i = 0; i < size(); i++) {
            data[i] = val;
        }
    }

    MyVec(const MyVec& rhs) {
        cout << "Calling copy constructor\n";
        copy(rhs);
    }

    ~MyVec() {
        cout << "Calling destructor\n";
        delete [] data;
    }

    MyVec& operator=(const MyVec& rhs) {
        cout << "Calling assignment operator\n";
        if (&rhs != this) {  // check for self-assign!
            delete [] data;
            copy(rhs);
        }
        return *this;
    }

    int operator[](int i) const {
        return data[i];
    }

    int& operator[](int i) {
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

    const int* begin() const { return data; }
    const int* end()   const { return data + sz; }

    int* begin() { return data; }
    int* end()   { return data + sz; }

    string get_name() const { return name; }

 private:
    size_t sz;
    size_t capac;
    string name;
    int* data;

    void copy(const MyVec& rhs) {
        sz = rhs.sz;
        capac = rhs.capac;
        name = rhs.name;
        data = new int[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = rhs.data[i];
        }
    }
};


void print_vec(const MyVec& ivec) {
    cout << ivec.get_name() << ' ';
    for (int item : ivec) {
        cout << item << ' ';
    }
    cout << endl;
}


void scale(MyVec& ivec, int scalar) {
    for (int& item : ivec) {
        item *= scalar;
    }
}


int main()
{
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec("v1");
    cout << "Vector memory = " << sizeof(v1) << endl;
    cout << "Vector number elements = " << v1.size() << endl;
    v1.push_back(4);
    v1.push_back(8);
    v1[1] = 6;
    scale(v1, 3);
    if (true) {
        MyVec v2(10, 42);
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
    v1 = MyVec(4);
//    cout << "Vector size = " << sizeof(v1) << endl;
    cout << "Vector number elements = " << v1.size() << endl;
    print_vec(v1);
//


    v1 = v1;
    cout << "Constructing v3\n";
    MyVec v3 = MyVec("v3");
    v3 = v1;
    print_vec(v3);
    print_vec(v1);

//
//    cout << "Done with test!\n";
    return 0;
}
