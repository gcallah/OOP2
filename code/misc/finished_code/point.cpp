/*
 * A simple look at C++ structs.
 * */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int NUM_DIMS = 5;
const int SCALAR = 4;

/*
 * We add a constructor here to initialize coords:
 * */
struct Point {
    vector<int> coords;
    Point() : coords(NUM_DIMS, 0) {}
};


int main() {
    Point p;
    vector<Point> points;

    /*
     * The following loop is hard-coded to 5 coordinates
     * to make the code simpler: `point_class.cpp` will
     * fix that problem.
     * */
    ifstream pfile("points5.txt");
    while (pfile >> p.coords[0] >> p.coords[1] >> p.coords[2]
            >> p.coords[3] >> p.coords[4]) {
        points.push_back(p);
    }

    for (Point& this_pt : points) {
        for (int& coord : this_pt.coords) {
            coord *= SCALAR;
        }
    }

    /*
     * The following loops could be re-written as ranged for loops
     * as well:
     * */
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < points[i].coords.size(); j++) {
            cout << points[i].coords[j] << " ";
        }
        cout << endl;
    }
}
