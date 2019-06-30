#include <iostream>
#include <vector>

int main() {
    std::vector<int*> iptrs;
    for (int i = 1; i <= 10; i++) {
        iptrs.push_back(new int(i));
    }
    for (int* ip : iptrs) {
        *ip *= 2;
    }
    for (int* ip : iptrs) {
        std::cout << *ip << " ";
    }
    std::cout << std::endl;
}
