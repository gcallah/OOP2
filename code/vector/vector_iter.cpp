/*
  Vector_iter
 * An `iterator` captures the general notion of traversing a data structure.
 * 
 * If a class provides an `iterator` you don't need to know its internals
 * to access all of its members!
 * 
 * What operations do we need in order to do this?
 *
 * - Where should we begin?
 * - Where should we stop?
 * - How do we know we're at the stopping point?
 * - How can we move forward?
 * - How can we get at the item we are currently on?
 *
 *   The answers are:
 *
 * - `begin()`
 * - `end()`
 * - `operator!=()`
 * - `operator++()`
 * - `operator*()`
 */
#include <iostream>
using namespace std;

class Vector {
public:
    class Iterator {
        friend bool operator!=(Iterator lhs, Iterator rhs) {
            return lhs.valPtr != rhs.valPtr;
        }
 public:
        Iterator(int* ptr) : valPtr(ptr) {}

        Iterator& operator++() {
            // if this were a linked list, we would have:
            // valPtr = val_ptr->next;
            ++valPtr;
            return *this;
        }

        int& operator*() {
            return *valPtr;
        }

 private:
        int* valPtr;
    };

    class ConstIterator {

 public:
        int operator*() {
            return *valPtr;
        }
 private:
        int* valPtr;
    };

    explicit Vector(size_t howMany = 0, int val=0) {
        theSize = howMany;
        theCapacity = howMany;
        data = new int[howMany];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = val;
        }
    }

    //
    // Copy control
    //
    //   Destructor
    ~Vector() {
        delete [] data;
    }

    //   Copy Constructor
    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    }

    //   Assignment Operator
    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            // Free up the old (destructor)
            delete [] data;
            // Allocate new
            data = new int[rhs.theCapacity];
            // Copy all the stuff
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            for (size_t i = 0; i < theSize; ++i) {
                data[i] = rhs.data[i];
            }
        }
        // Return ourselves
        return *this;
    }

    void push_back(int val) {
        if (theSize == theCapacity) {
            if (theCapacity == 0) {
                delete [] data;
                data = new int[1];
                theCapacity = 1;
            } else {
                int* oldData = data;
                theCapacity *= 2;
                data = new int[theCapacity];
                for (size_t i = 0; i < theSize; ++i) {
                    data[i] = oldData[i];
                }
                delete [] oldData;
            }
        }
        data[theSize++] = val;
    }

    size_t size() const { return theSize; }
    void pop_back() { --theSize; }
    void clear() { theSize = 0; };


    // Square brackets?
    int operator[](size_t index) const {
        return data[index];
    }
    int& operator[](size_t index) {
        return data[index];
    }
    
    // // begin() returns an "iterator" pointing to the first item.
    // int* begin() { return data; }
    // // end() returns an "iterator" pointing just past the last item.
    // int* end() { return data + theSize; }

    Iterator begin() { 
        return Iterator(data); 
        // Iterator result(data);
        // return result;
    }

    Const_Iterator begin() const { 
        return Const_Iterator(data); 
        // Iterator result(data);
        // return result;
    }

    Iterator end() { return Iterator(data + theSize); }

    Const_Iterator end() const { return Const_Iterator(data + theSize); }

    // The following two lines would allow modifying a const vector!!!
    //    const int* begin() const { return data; }
    //    const int* end() const { return data + theSize; }

private:
    int* data;
    size_t theSize;
    size_t theCapacity;
};


// void printVector(const Vector& vec) {
//
//
//
//
void printVector(const Vector& vec) {
    for (Vector::Iterator iter = vec.begin(); iter != vec.end(); ++iter) {
         cout << *iter << ' ';
    }

    // need return to be const int* to block
    // for (int& val : vec) cout << val << ' ';
    cout << endl;
}

int main() {

    // Not templated.  Our Vector class can only hold ints.
    Vector v;  

    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
    printVector(v);
    /*
    printVector(v);

    v[0] = 100;

    Vector v2 = v;
    printVector(v2);

    Vector v3;
    v3 = v;
    printVector(v3);

    v3 = Vector(17);
    printVector(v3);

    cout << endl;

//    for (int val : v2) {
//        cout << val << ' ';
//    }
    cout << endl;

//    for (Vector::Iterator iter = v2.begin(); iter != v2.end(); ++iter) {
//        int val = *iter;
//        //cout << *iter << ' ';
//        cout << val << ' ';
//    }
    cout << endl;

//    for (int& val : v2) {
//        val += 1;
//    }
//    
//    for (int val : v2) {
//        cout << val << ' ';
//    }
    cout << endl;

    */
}


