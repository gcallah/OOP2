/*
 * We are going to massage a `struct` into a `class` in this
 * program, and introduce class features like public/private
 * distinction, member functions, and constant member functions.
 * */
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


/*
 * We changed our Point struct to a class.
 * It captures the mathematical notion of a vector.
 * */
class Point {
    // overload output operator
    friend ostream& operator<<(ostream& os, const Point& p) {
        for (size_t j = 0; j < p.dim(); j++) {
            os << p.coords[j] << " ";
        }
        return os;
    }

public:
    Point(size_t num_dims) : coords(num_dims, 0) {}

    int get_coord(int i) const { return coords[i]; }
    size_t dim() const { 
        return coords.size();
    }
    
    double magnitude();

    void set_coord(int i, int val) {
        coords[i] = val;
        changed = true;
    }

    void scale(int scalar);

private:
    double last_magnitude = 0.0;
    bool changed = true;
    vector<int> coords;
};


/*
 * We can use the fact we have a class to save previous results:
 * if the `Point` has not changed, then re-use previously calculated
 * magnitude. If not, re-calculate.
 * */
double Point::magnitude() {
    if (changed) {
        int sq_sum = 0;
        for (int coord : coords) sq_sum += pow(coord, 2);
        last_magnitude = sqrt(sq_sum);
        changed = false;
    }
    return (last_magnitude);
}


void Point::scale(int scalar) {
    for(int& i : coords) {
        i *= scalar;
    }
}

/*
 * The following is just showing why we need to declare `dim()` to be 
 * `const`.
 * */
void examine_point(const Point& p) {
    p.dim();
}


/*
 * If we have time, we build a VectorSpace class.
 * We can build a scale method that changes the whole vector space.
 * */
int main() {
    int dim;
    string filenm;
    cout << "Enter a dimension and file name: ";
    cin >> dim >> filenm;

    Point p(dim);
    vector<Point> points;

    ifstream pfile(filenm);

    for (size_t i = 0; i < p.dim(); i++) {
        p.set_coord(i, i);
    }
    p.scale(4);
    points.push_back(p);

    while (pfile) {
        for (size_t i = 0; i < p.dim(); i++) {
            int coord;
            pfile >> coord;
            if (pfile) p.set_coord(i, coord);
            else break;
        }
        if (pfile) points.push_back(p);
    }

    for (size_t i = 0; i < points.size(); i++) {
        cout << points[i] << endl;
        cout << "Magnitude of point is: "
            << points[i].magnitude() << endl;
    }
}
