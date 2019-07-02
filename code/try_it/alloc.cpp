#include <iostream>

int main() {
    int** ipp = new int*[5];
    for (int i = 0; i < 5; i++)
        ipp[i] = new int(i);
    for (int i = 0; i < 5; i++)
        std::cout << "i-th elem: " << *(ipp[i]) << std::endl;
}
