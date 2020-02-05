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
    // make this public and add dims as param:
public:
    Point() : coords(NUM_DIMS, 0) {}
    int get_coord(int i) { return coords[i]; }
    void set_coord(int i, int val) { coords[i] = val; }
    size_t dim() { return coords.size(); }
    // add magnitude()
    // make this private:
private:
    vector<int> coords;
};


int main() {
    // discuss why the following line now fails:
    Point p;
    vector<Point> points;

    ifstream pfile("points5.txt");

    for (int i = 0; i < NUM_DIMS; i++) {
        p.set_coord(i, i * SCALAR);
    }
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
        for (size_t j = 0; j < points[i].dim(); j++) {
            cout << points[i].get_coord(j) << " ";
        }
        cout << endl;
    }
}
