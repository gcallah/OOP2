#include <iostream>
using namespace std;

const int DEF_VSIZE = 2;


class MyVec {
 public:
    MyVec() {
        sz = 0;
        capac = DEF_VSIZE;
        data = new int[DEF_VSIZE];
    }

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

    int operator[](int i) {
        return data[i];
    }

    void push_back(int val) {
        sz++;
        if (sz > capac) {
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
    int sz;
    int capac;
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
    
    cout << "Size of v3 is: " << v3.size() << endl;
    for(int i = 0; i < v2.size(); i++)
        cout << v2[i] << endl;
//    for(int i = 0; i < v3.size(); i++)
//        cout << v3[i] << endl;

    cout << "Done with test!\n";
    return 0;
}
