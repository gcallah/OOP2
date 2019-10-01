
/*
 * A place to experiment with vectors and see what various
 * operations do.
 * */

#include <iostream>
#include <vector>

using namespace std;


/*
 * This will be a type with copy control that also
 * prints when its copy control members are called
 * so when can track their usage.
 * */
class ATestType {
    friend ostream& operator<<(ostream& os, const ATestType& t);

 public:
    ATestType(char c, int i) : id(c), iptr(new int(i)) {}

    /*
     * Copy constructor: copies the storage pointed to
     * by `iptr` for the new object.
     * */
    ATestType(const ATestType& source) {
        id = source.id;
        cout << "In ATestType copy constructor for " << id << endl;
        iptr = new int(*(source.iptr));
    }

    /*
     * Destructor: deletes the storage pointed to by `iptr`.
     * */
    ~ATestType() { delete iptr; }

    int get_val()  { return *iptr; }
    void set_val(int n)  { *iptr = n; }

 private:
    char id;
    int* iptr;
};


ostream& operator<<(ostream& os, const ATestType& t) {
    os << "ATestType " << t.id << " has val " << *(t.iptr) << endl;
    return os;
}


/*
 * Print a vector of T, where T must be a type that
 * implements `operator<<()`.
 * */
template <typename T>
void print_vector(ostream& os, vector<T> vec) {
    for (auto mbr : vec) {
        os << mbr << ' ';
    }
    os << endl;
}


/*
 * We can see that by using emplace_back() for att2,
 * we save one call to the copy constructor.
 * */
int main() {
    vector<int> ivec{5, 6, 7, 8};
    print_vector(cout, ivec);

    ATestType att1{'1', 16};
    ATestType att2{'2', 32};

    vector<ATestType> att_vec;
    cout << "Pushing back att1\n";
    att_vec.push_back(att1);
    cout << "Emplacing back att2\n";
    att_vec.emplace_back(att2);
    print_vector(cout, att_vec);
}
