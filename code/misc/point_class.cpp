/*
 * We are going to massage a `struct` into a `class` in this
 * program, and introduce class features like public/private
 * distinction, member functions, and constant member functions.
 * */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// let's eliminate NUM_DIMS:
const int NUM_DIMS = 5;
const int SCALAR = 4;

/*
 * We will change this struct to a class.
 * It's going to capture the mathematical notion of a vector.
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
    // pass num_dims as param:
    Point() : coords(NUM_DIMS, 0) {}

    int get_coord(int i) const { return coords[i]; }
    size_t dim() const { 
        return coords.size();
    }
    
    // add magnitude()
    double magnitude() {
    }

    void set_coord(int i, int val) { coords[i] = val; }

    void scale(int scalar) {
        for(int& i : coords) {
            i *= scalar;
        }
    }

private:
    vector<int> coords;
};


void examine_point(const Point& p) {
    p.dim();
}


/*
 * If we have time, we build a VectorSpace class.
 * We can build a scale method.
 * */
int main() {
    Point p;
    vector<Point> points;

    ifstream pfile("points5.txt");

    for (int i = 0; i < NUM_DIMS; i++) {
        p.set_coord(i, i);
    }
    p.scale(4);
    points.push_back(p);

    // let's see how NOT to hard code this:
    /*
    while (pfile >> p.coords[0] >> p.coords[1] >> p.coords[2]
            >> p.coords[3] >> p.coords[4]) {
        points.push_back(p);
    }

    for (Point& this_pt : points) {
        for (int& coord : this_pt.coords) {
            coord *= SCALAR;
        }
    }
    */

    // re-write these loops:
    for (size_t i = 0; i < points.size(); i++) {
        cout << points[i] << endl;
    }
}
