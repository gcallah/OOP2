#include <iostream>
using namespace std;

const size_t DEF_VCAPACITY = 2;
const int CAPACITY_MULT = 2;


class MyVec {
 public:
    // default constructor:
    MyVec() {
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new int[DEF_VCAPACITY];
    }

    explicit MyVec(size_t sz, int val=0) : sz(sz) {
        capac = max(sz * CAPACITY_MULT, DEF_VCAPACITY);
        data = new int[capac];
        cout << "data address = " << data << endl;
        for (size_t i = 0; i < sz; i++) data[i] = val;
    }

    // copy constructor:
    MyVec(const MyVec& v2) {
        copy(v2);
    }

    MyVec& operator=(const MyVec& v2) {
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }

    ~MyVec() {
        delete [] data;
    }

    int operator[](int i) const {
        return data[i];
    }

    int& operator[](int i) {
        return data[i];
    }

    void push_back(int val) {
        sz++;
        if (sz > capac) {
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new int[capac * CAPACITY_MULT];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capac *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }

    size_t size() const { return sz; }

 private:
    size_t sz;
    size_t capac;
    int* data;
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capac = v2.capac;
        data = new int[capac];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
};


void print_vec(const MyVec& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}


int main()
{
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec();
    for(int i = 0; i < 16; i++) {
        v1.push_back(i * 2);
    }

    MyVec v2 = MyVec(v1);
    MyVec v3 = MyVec();
    v3 = v1;
    // MyVec v4 = MyVec(0);
    MyVec v4 = MyVec(10);
    
    cout << "Size of v3 is: " << v3.size() << endl;
    cout << "v2 = \n";
    v2[0] = 999;
    print_vec(v2);
    cout << "v3 = \n";
    print_vec(v3);
    cout << "v4 = \n";
    print_vec(v4);

    cout << "Done with test!\n";
    return 0;
}
