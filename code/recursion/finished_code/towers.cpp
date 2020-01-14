/*
 * The Towers of Hanoi in C++.
 * This illustrates how recursion can make what might be 
 * a complex problem to solve with a loop very simple
 * with recursion.
 * */
#include <iostream>

using namespace std;

const int DISKS = 3;

/*
 * In order to solve a tower of height *n*, we solve the
 * problem for height *n* - 1, then make a single disk move
 * (the "work" for that recursion level), and then solve the
 * *n* - 1 problem again, with different parameters for
 * `start`, `spare`, and `goal`.
 * */
void towers(int n, char start, char goal, char spare) {
    if (n == 0) return;

    // the initial recursive call:
    towers(n - 1, start, spare, goal);
    // the "work":
    cout << "Moving disk " << n << " from " << start << " to "
        << goal << endl;
    // the second recursive call:
    towers(n - 1, spare, goal, start);
}

int main() {
    cout << "Solving the towers problem for " << DISKS << "\n";
    towers(DISKS, 'A', 'B', 'C');
}
