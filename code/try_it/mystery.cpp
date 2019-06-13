#include <iostream>

void mystery(int* a, int* b)
{
    int c = *b + 1;
    *b = *a + 1;
    *a = c;
}

int main()
{
    int p = 6, q = 4;
    mystery(&p, &q);
    std::cout << p << ' ' << q << std::endl;
    return 0;
}

