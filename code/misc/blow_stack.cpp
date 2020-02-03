#include <iostream>

void f(int i) {
    std::cout << i << std::endl;
    f(i + 1);
}

int main() {
    f(0);
}
