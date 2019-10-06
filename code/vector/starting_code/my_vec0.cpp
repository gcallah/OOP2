#include <iostream>
using namespace std;

const int DEF_VCAPACITY = 2;


class MyVec {
 public:
    MyVec() {
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new int[DEF_VCAPACITY];
    }

    int operator[](int i) {
        return data[i];
    }

    void push_back(int val) {
        sz++;
        if (sz == capac) {  // we're about to up it!
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new int[capac * 2];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capac *= 2;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }

    size_t size() { return sz; }

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


void print_vec(MyVec ivec) {
    for (size_t i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << ' ';
    }
    cout << endl;
}


int main()
{
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec();
    cout << "Vector size = " << sizeof(v1) << endl;
    v1.push_back(4);
    v1.push_back(8);
    v1.push_back(16);
    v1.push_back(32);
    v1.push_back(64);
    cout << "Vector size = " << sizeof(v1) << endl;
    print_vec(v1);

    /*
    cout << "Constructing v2\n";
    MyVec v2 = v1;

    cout << "Constructing v3\n";
    MyVec v3 = MyVec();
    v3 = v1;
    
    cout << "Size of v3 is: " << v3.size() << endl;

    print_vec(v2);
    print_vec(v3);

    */

    cout << "Done with test!\n";
    return 0;
}
