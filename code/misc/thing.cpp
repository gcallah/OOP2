#include <iostream>
using namespace std;

struct Thing {
    int val;
    Thing(int i) : val(i) {}
};

int main() {
    Thing** datap = new Thing*[100];
    for (int i = 0; i < 100; i++)
        datap[i] = new Thing(i);

    for (int i = 0; i < 100; i++) {
        datap[i]->val += i;
        cout << datap[i]->val << " ";
    }
    cout << endl;
}
