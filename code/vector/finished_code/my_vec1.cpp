#include <iostream>
#include <string>
using namespace std;

const int DEF_VCAPACITY = 2;
const int EXTRA_CAPACITY = 2;


template <typename T>
class MyVec {
 public:
    MyVec() {
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new T[DEF_VCAPACITY];
    }

    explicit MyVec(size_t items, T init_val) {
        sz = items;
        capac = items * EXTRA_CAPACITY;
        data = new T[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = init_val;
        }
    }

    MyVec(const MyVec& source) {
        // cout << "Calling copy constructor\n";
        copy(source);
    }

    ~MyVec() {
        // cout << "Calling destructor\n";
        delete [] data;
    }

    MyVec& operator=(const MyVec& source) {
        // cout << "Calling assignment operator\n";
        if (this != &source) {
            delete [] data;
            copy(source);
        }
        return *this;
    }

    T& operator[](int i) {
        return data[i];
    }

    T operator[](int i) const {
        return data[i];
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + sz;
    }

    T* begin() { return data; }

    T* end() { return data + sz; }

    void clear() {
        sz = 0;
    }

    T back() const { return data[sz - 1]; }
    T& back() { return data[sz - 1]; }

    void pop_back() {
        if (sz > 0) sz--;
    }

    void push_back(T val) {
        sz++;
        if (sz == capac) {  // we're about to up it!
            cout << "Increasing capacity\n";
            T* old_data = data;
            data = new T[capac * EXTRA_CAPACITY];
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
    T* data;

    void copy(const MyVec& source) {
        sz = source.sz;
        capac = source.capac;
        data = new T[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = source.data[i];
        }
    }
};


double deref(double* dptr) {
    return *dptr;
}


class Oops {
    friend ostream& operator<<(ostream& os, const Oops& oops) {
        os << oops.ch;
        return os;
    }

    public:
        Oops() : ch('!') {}
        char ch;
};


template <typename Printable>
void print_vec(const MyVec<Printable>& vec, const string& msg) {
    cout << "\n**************\n" << msg << endl;
    for (Printable item : vec) {
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

    MyVec<int> v4(10, 7);
    print_vec(v4, "before v4 contains:");
    v4 = MyVec<int>(9, 0);
    cout << "v4 last elem = " << v4.back() << endl;
//    print_vec(v4, "after v4 contains:");
    MyVec<char> vc = MyVec<char>(9, 'a');
    print_vec(vc, "vc contains:");
    MyVec<double> vd = MyVec<double>(9, 2.4);
    print_vec(vd, "vd contains:");
    MyVec<Oops> oops = MyVec<Oops>(4, Oops());
    print_vec(oops, "oops contains:");

    cout << "Done with test!\n";
    return 0;
}
