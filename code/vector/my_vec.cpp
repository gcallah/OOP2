/*
 * This file illustrates how we might implement our own 
 * version of std::vector.
 * It includes *copy control* and an *iterator*.
 * */
#include <iostream>
using namespace std;

const size_t DEF_VCAPACITY = 2;
const int CAPACITY_MULT = 2;


class MyVec {
    /*
     * The MyVec class that is a partial version of std::vector.
     * */
 public:
    class Iterator {
        /*
         * This class supports ranged for loops,
         * as well as algorithms like the STL ones
         * that expect iterators as arguments.
         * It includes the operators necessary
         * to support iteration.
         * */
            friend bool operator!=(Iterator& rhs, Iterator& lhs) {
                return rhs.iptr != lhs.iptr;
            }

            friend bool operator==(Iterator& rhs, Iterator& lhs) {
                return rhs.iptr == lhs.iptr;
            }

        public:
            Iterator(int* ip) : iptr(ip) {}

            Iterator& operator++() {
                ++iptr;
                return *this;
            }

            int operator*() { return *iptr; }

        private:
            int* iptr;
    };


    MyVec() {
        /*
         * This if the default constructor for the class.
         * */
        sz = 0;
        capac = DEF_VCAPACITY;
        data = new int[DEF_VCAPACITY];
    }

    /*
     * Another constructor: note the use of `explicit`:
     * it means we can't accidentally get a "weird"
     * interpretation of some code as implicitly calling
     * this constructor.
     * */
    explicit MyVec(size_t sz, int val=0) : sz{sz} {
        capac = max(DEF_VCAPACITY, sz * CAPACITY_MULT);
        data = new int[capac];
        for (size_t i = 0; i < sz; i++) data[i] = val;
    }

    /*
     * This is the copy constructor for our class.
     * It calls a method called `copy` so that we can share
     * that code with assignment.
     * */
    MyVec(const MyVec& v2) {
        copy(v2);
    }

    /*
     * The assignment operator essentially combines the
     * destructor and the copy constructor.
     * */
    MyVec& operator=(const MyVec& v2) {
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }

    /*
     * The destructor for this class.
     * */
    ~MyVec() {
        delete [] data;
    }

    int operator[](size_t i) const {
        /*
         * This version of the [] operator is const, so it
         * is used when we are just getting the value of
         * a vector element.
         * */
        return data[i];
    }

    int& operator[](int i) {
        /*
         * This version of the [] operator is not const,
         * so it is used when we are setting the value of
         * a vector element.
         * */
        return data[i];
    }

    void push_back(int val) {
        /*
         * This method puts a val on the end of our vector:
         * it may need to increase the vector's capacity
         * in order to do this.
         * */
        sz++;
        if (sz > capac) {
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new int[capac * CAPACITY_MULT];
            for (size_t i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capac *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }

    size_t size() const { return sz; }

    Iterator begin() const {
        return Iterator(data);
    }

    Iterator end() const {
        return Iterator(data + size());
    }

 private:
    size_t sz;
    size_t capac;
    int* data;
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capac = v2.capac;
        data = new int[capac];
        for (size_t i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
};


void print_vec(const MyVec& v) {
    for(int i : v) cout << i << endl;
}


int main() {
    cout << "Testing my_vec:\n";

    MyVec v1 = MyVec();
    for(int i = 0; i < 16; i++) {
        v1.push_back(i * 2);
    }

    MyVec v2 = MyVec(v1);
    MyVec v3 = MyVec();
    v3 = v1;
    v2 = v2;
    /*
     * This line won't work if we have `explicit` on the
     * constructor for MyVec(int, int):
     * MyVec v4 = 12;
     * */
    MyVec v4 = MyVec(12);
    
    cout << "Size of v3 is: " << v3.size() << endl;
    v2[0] = 999;
    cout << "v4 = \n";
    // print_vec(v4);
    v2 = v2;
    print_vec(v2);
    
    cout << "Done with test!\n";
    return 0;
}
