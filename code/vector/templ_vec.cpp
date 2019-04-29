/*
 * This file illustrates how we might implement our own 
 * version of std::vector.
 * In particular, this version makes it a template.
 * */
#include <iostream>
#include <algorithm>
using namespace std;

const size_t DEF_VCAPACITY = 2;
const int CAPACITY_MULT = 2;


template <typename T>
class MyVec {
    /*
     * The MyVec class that is a partial version of std::vector.
     * */
 public:
    MyVec() {
        /*
         * This if the default constructor for the class.
         * */
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new T[DEF_VCAPACITY];
    }

    explicit MyVec(size_t sz, T val=T()) : sz{sz} {
        /*
         * Another constructor: note the use of `explicit`:
         * it means we can't accidentally get a "weird"
         * interpretation of some code as implicitly calling
         * this constructor.
         * */
        capac = max(DEF_VCAPACITY, sz * CAPACITY_MULT);
        data = new T[capac];
        for (size_t i = 0; i < sz; i++) data[i] = val;
    }

    MyVec(const MyVec& v2) {
        /*
         * This is the copy constructor for our class.
         * It calls a method called `copy` so that we can share
         * that code with assignment.
         * */
        copy(v2);
    }

    MyVec& operator=(const MyVec& v2) {
        /*
         * The assignment operator essentially combines the
         * destructor and the copy constructor.
         * */
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }

    ~MyVec() {
        /*
         * The destructor for this class.
         * */
        delete [] data;
    }

    T operator[](int i) const {
        /*
         * This version of the [] operator is const, so it
         * is used when we are just getting the value of
         * a vector element.
         * */
        return data[i];
    }

    T& operator[](int i) {
        /*
         * This version of the [] operator is not const,
         * so it is used when we are setting the value of
         * a vector element.
         * */
        return data[i];
    }

    void push_back(T val) {
        /*
         * This method puts a val on the end of our vector:
         * it may need to increase the vector's capacity
         * in order to do this.
         * */
        sz++;
        if (sz > capac) {
            cout << "Increasing capacity\n";
            T* old_data = data;
            data = new T[capac * CAPACITY_MULT];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capac *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }

    size_t size() const { return sz; }

    T* begin() { return data; }
    T* end()   { return data + size(); }

 private:
    size_t sz;
    size_t capac;
    T* data;

    void copy(const MyVec& v2) {
        sz = v2.sz;
        capac = v2.capac;
        data = new T[capac];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
};

struct Cat {
    friend ostream& operator<<(ostream& os, const Cat& cat) {
        return os << "meow ";
    }
};

template <typename T>
void print_vec(const MyVec<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}


int main() {
    cout << "Testing my_vec:\n";

    MyVec<int> v1 = MyVec<int>();
    for(int i = 0; i < 16; i++) {
        v1.push_back(i * 2);
    }

    MyVec<int> v2 = MyVec<int>(v1);
    MyVec<Cat> v_cat = MyVec<Cat>(5);
    v2 = v2;
    // MyVec<int> v4 = 12;
    MyVec<int> v4 = MyVec<int>(12);
    
    cout << "Size of v_cat is: " << v_cat.size() << endl;
    cout << "v2 = \n";
    v2[0] = 999;
    print_vec(v2);
    cout << "v_cat = \n";
    print_vec(v_cat);
    cout << "v4 = \n";
    print_vec(v4);
    v2 = v2;
    sort(v2.begin(), v2.end());
    print_vec(v2);
    print_vec(v_cat);

    cout << "Done with test!\n";
    return 0;
}
