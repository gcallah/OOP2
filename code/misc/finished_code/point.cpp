/*
 * A simple look at C++ structs.
 * */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int NUM_DIMS = 5;

struct Point {
    vector<int> coords;

    Point() : coords(NUM_DIMS, 0) {}
};


int main() {
    vector<Point> points;
    Point p;

    ifstream pfile("points5.txt");
    while (pfile >> p.coords[0] >> p.coords[1] >> p.coords[2]
            >> p.coords[3] >> p.coords[4]) {
        points.push_back(p);
    }
    for (Point this_p : points) {
        for (int coord : this_p.coords) {
            cout << coord << " ";
        }
        cout << endl;
    }
}
