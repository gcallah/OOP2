/*
 * Testing some template variation
 * */
#include <vector>
#include <iostream>
using namespace std;

template<typename T, typename U>
int count(T collection, U target) {
    int count = 0;
    for(U item: collection)
        if (item == target) count++;
    return count;
}


/*
 * Just set up count, call, and print result.
 * */
int main() {
    vector<int> v = {1, 2, 2, 3, 3, 3};
    cout << "count = " << count(v, 2) << "\n";
}
