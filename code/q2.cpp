// 2019 Spring Exam Two, Question 2
// Test concept of [const] pointer to [const]

#include <iostream>
using namespace std;

void foo(int x) {
    int* const p = &x;
    x = 17;
    cout << *p << ' ';
    *p = 28;
}

int main() {
    //int y = d2;
    int y = 42;
    foo(y);
    cout << y << endl;
}
