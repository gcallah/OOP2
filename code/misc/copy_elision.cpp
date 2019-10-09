#include <iostream>

using namespace std;


struct S {
    S() = default;
    S(S&&) = delete;
    S(const S&) = delete;
    int val = 12;
};


auto s_factory() {
    return S{};
}


int main() {
    S s = s_factory();
    cout << "Got an s with a val of " << s.val << endl;
}

