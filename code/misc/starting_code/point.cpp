/*
 * A simple look at C++ structs.
 * */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Point {
    int x, y, z;
};


int main() {
    Point p;
    vector<Point> points;

    ifstream pfile("misc/points.txt");
    while (pfile >> p.x >> p.y >> p.z) {
        points.push_back(p);
    }
    for (Point this_p : points) {
        cout << this_p.x << ' ' << this_p.y << ' ' << this_p.z << endl;
    }
}
