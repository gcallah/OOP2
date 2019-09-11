/*
 * A simple look at C++ structs.
 * */
#include <iostream>
using namespace std;

struct Point {
    int x, y, z;
};


int main() {
    Point p;

    cout << p.x << ' ' << p.y << ' ' << p.z << endl;
}
