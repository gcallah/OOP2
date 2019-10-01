
/*
 * A place to experiment with vectors and see what various
 * operations do.
 * */

#include <iostream>
#include <vector>

using namespace std;


/*
 * `ATestType` is a type with copy control that also
 * prints when its copy control members are called
 * so we can track their usage.
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
    ~ATestType() {
        cout << "In ATestType destructor for " << id << endl;
        delete iptr;
    }

    int get_val()  { return *iptr; }
    void set_val(int n)  { *iptr = n; }

 private:
    char id;
    int* iptr;
};


ostream& operator<<(ostream& os, const ATestType& t) {
    os << "|ATestType " << t.id << " has val " << *(t.iptr) << "|";
    return os;
}


/*
 * Print a vector of T, where T must be a type that
 * implements the stream output operator.
 * */
template <typename Streamable>
void print_vector(ostream& os, vector<Streamable> vec) {
    for (auto& mbr : vec) {
        os << mbr << ' ';
    }
    os << endl;
}


void section_head(const string& s) {
    cout << "\n***********************\n";
    cout << s << endl;
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
    section_head("Pushing back att1");
    att_vec.push_back(att1);
    section_head("Emplacing back att2");
    att_vec.emplace_back(att2);

    section_head("Printing att vec");
    print_vector(cout, att_vec);

    section_head("Clearing the att vector");
    att_vec.clear();

    section_head("Exiting program");
}
