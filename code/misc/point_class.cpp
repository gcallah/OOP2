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
struct Point {
    // make this public and add dims as param:
    Point() : coords(NUM_DIMS, 0) {}
    // add get_coord()
    // add set_coord()
    // add dim()
    // add magnitude()
    // make this private:
    vector<int> coords;
};


int main() {
    // discuss why the following line now fails:
    Point p;
    vector<Point> points;

    ifstream pfile("points5.txt");
    // let's see how NOT to hard code this:
    while (pfile >> p.coords[0] >> p.coords[1] >> p.coords[2]
            >> p.coords[3] >> p.coords[4]) {
        points.push_back(p);
    }

    for (Point& this_pt : points) {
        for (int& coord : this_pt.coords) {
            coord *= SCALAR;
        }
    }

    // re-write these loops:
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < points[i].coords.size(); j++) {
            cout << points[i].coords[j] << " ";
        }
        cout << endl;
    }
}
