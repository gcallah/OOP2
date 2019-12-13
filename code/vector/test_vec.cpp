#include <iostream>
#include <vector>
#include <string>
using namespace std;

// implementing MyVec
class MyVec {
public:
    // constructors
    MyVec(size_t s = 0, size_t cp = 0): sz(s), capacity(cp), data(new int[capacity]) {};
    MyVec(size_t s, int value=0): sz(s), capacity(s) {
        data = new int[capacity];
        for (size_t i=0; i<sz; i++) {
            data[i] = value;
        }
    }
    
    // copy constructor
    MyVec(const MyVec& rhs) {
        sz = rhs.sz;
        capacity = rhs.capacity;
        data = new int[capacity];
        for (size_t i=0; i<sz; i++) {
            data[i] = rhs.data[i];
        }
    }
    
    // destructor
    ~MyVec() {
        delete [] data;
    }
    
    // assignment operator
    MyVec& operator=(const MyVec& rhs) {
        sz = rhs.sz;
        capacity = rhs.capacity;
        delete [] data;
        data = new int[capacity];
        for (size_t i=0; i<sz; i++) {
            data[i] = rhs.data[i];
        }
        return *this;
    }
    
    // size
    size_t size() const {return sz;}
    
    // pop_back
    void pop_back() {sz--;}
    
    // clear
    void clear() {sz = 0;}
    
    // push_back
    void push_back(int value) {
        if (sz == capacity) {
            int* old = data;
            capacity *= 2;
            data = new int[capacity];
            for (size_t i=0; i<sz; i++) {
                data[i] = old[i];
            }
            delete [] old;
        }
        data[sz] = value;
        sz++;
    }
    
    
    // operator[]
//    int& operator[](size_t i) {
//        return data[i];
//    }
//    int operator[](size_t i) const {
//        return data[i];
//    }
    int& operator[](size_t i) const { // operator[]
        return data[i];
    }
    
    
    // iterator
    int* begin() const {return data;}
    int* end() const {return data + sz;}
    
    // back
    int& back() const {return data[sz-1];}
    
    
    
private:
    size_t sz;
    size_t capacity;
    int* data;
};


ostream& operator<<(ostream& os, const MyVec& myvec) {
//    for (size_t i=0; i<myvec.size(); i++) {
//        cout << myvec[i] << " ";
//    }
//    cout << endl;
    for (int i : myvec) {
        cout << i << " ";
    }
    cout << endl;
    return os;
}

int main() {
    MyVec v1;
    v1.push_back(42);
    v1.push_back(17);
    v1.push_back(68);
    v1.push_back(50);
    cout << v1 << endl;
    
    v1[2] = 40;
}
