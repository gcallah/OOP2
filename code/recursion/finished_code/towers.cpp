/*
 * The Towers of Hanoi in C++.
 * */
#include <iostream>

using namespace std;

void towers(int n, char start, char goal, char spare) {
    if (n == 0) return;

    towers(n - 1, start, spare, goal);
    cout << "Moving disk " << n << " from " << start << " to "
        << goal << endl;
    towers(n - 1, spare, goal, start);
}

int main() {
    cout << "Hello world!\n";
    towers(3, 'A', 'B', 'C');
}
