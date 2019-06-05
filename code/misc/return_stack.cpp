#include <iostream>

using namespace std;


int* f(int n) {
    int* ret = new int;
    *ret = n * n * n;
    return ret;
}

int g(int n) {
    int x = 7;
    int y = 12;
    return y * x * n;
}

int main() {
    cout << "Hello\n";
    int* iptr = f(3);
    cout << "Cube of 3 = " << *iptr << endl;
    for (int i = 0; i < 4; i++) {
        int j = g(i);
        cout << j << endl;
    }
    cout << "Cube of 3 = " << *iptr << endl;
    cout << "Goodbye\n";
}
